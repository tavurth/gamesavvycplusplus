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

tcp::Client::Client(TCPsocket newSocket, Host * newParent) {
	socket = newSocket;
	parent = newParent;
	if (!(ip = SDLNet_TCP_GetPeerAddress(newSocket)))
		net_error();
}

tcp::Client::Client() {
}

tcp::Client::~Client() {
}
        
void tcp::Client::kill() {
	if (thread)
		SDL_KillThread(thread);
	thread = NULL;
}

SDL_Thread * tcp::Client::set_thread(SDL_Thread * newThread) { thread = newThread; return thread; }
SDL_Thread * tcp::Client::get_thread() const { return thread; }

Host * tcp::Client::get_parent() const { return parent; }
