//		Copyright (c) William Whitty 2010
//
//     This file is part of GSC. 
//
//     GSC is free software: you can redistribute it and/or modify
//     it under the terms of the GNU Lesser General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     GSC is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU Lesser General Public License for more details.
//
//     You should have received a copy of the GNU Lesser General Public License
//     along with GSC.  If not, see <http://www.gnu.org/licenses/>.

#include "../../headers/GSC.h"

using namespace gsc;
using namespace tcp;

//Listen for incoming connections
int gsc::tcp::host_loop(void * data) {
	Host * parent = (Host *) data;
	TCPsocket newConnection;

	while (parent->get_flags() & IS_ACTIVE) {
		//Check to see if we've updated the new client function
		host_function newClientFunction = parent->get_function();

		//Accept any new connections
		if ((newConnection = SDLNet_TCP_Accept(parent->get_socket()))) {
			//Call the new client function and send the connection info
			Client * temp = new Client(newConnection, parent);
			parent->add_client(temp);

			//Create our client thread
			if (newClientFunction)
				if (!(temp->set_thread(SDL_CreateThread((int (*)(void *))newClientFunction, (void *) temp))))
					thread_error();
		}

		SDL_Delay(parent->get_sleep_delay());
	}
	return 0;
}

void Host::init() {
	//Create our IP
	if ((SDLNet_ResolveHost(ip, NULL, port)) == -1)
		net_error();
	
	//Open the socket
	if (!(socket = SDLNet_TCP_Open(ip)))
		net_error();

	//Start the host thread
	if (!(thread = SDL_CreateThread((int (*)(void *))host_loop, (void *)this)))
		thread_error();
}

//Constructor
Host::Host(Uint16 newPort) : Socket_Base(newPort) {
	flags = IS_ACTIVE;
	sleepDelay = 150;

	init();
}

Host::~Host() {
	close_socket();
	flags ^= IS_ACTIVE;
	SDL_WaitThread(thread, NULL);

	std::vector<Client *>::iterator it;

	for (it = clientList.begin(); it < clientList.end(); it++)
		(*it)->kill();
}

void Host::set_sleep_delay(Uint16 newDelay) { sleepDelay = newDelay; }
Uint16 Host::get_sleep_delay() const { return sleepDelay; }

void Host::set_function(host_function newFunction) { function = newFunction; }
host_function Host::get_function() const { return function; }

int Host::get_flags() const { return flags; }
void Host::set_flags(int newFlags) { flags = newFlags; }

std::vector<Client *> Host::get_clients() const { return clientList; }
void Host::add_client(Client * newClient) { clientList.push_back(newClient); }

//IP
void Host::set_ip(std::string newIP) { 
	ipString = newIP;
	init();
}
