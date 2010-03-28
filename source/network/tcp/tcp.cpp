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

const int gsc::tcp::IS_ACTIVE = 1;

int gsc::tcp::client_begin(Client * newClient) {
	Host * parent = newClient->get_parent();

	//Call the client_loop function
	(*parent->get_client_loop_function())(newClient);

	//When we fall out of the client loop, delete the client;
	delete(newClient);
	return 0;
}

//Listen for incoming connections
int gsc::tcp::host_loop(void * data) {
	Host * parent = (Host *) data; Client * temp;
	TCPsocket newConnection;

	while (parent->get_flags() & IS_ACTIVE) {
		//Accept any new connections
		if ((newConnection = SDLNet_TCP_Accept(parent->get_socket()))) {
			//Call the new client function and send the connection info
			temp = new Client(newConnection, parent);
			parent->add_client(temp);

			//Create our new client thread
			if (!(temp->set_thread(SDL_CreateThread((int (*)(void *))client_begin, temp))))
				thread_error();
		}

		SDL_Delay(parent->get_sleep_delay());
	}
	return 0;
}

void tcp::delete_all() {
	delete_all_hosts();
	delete_all_remotes();
}
