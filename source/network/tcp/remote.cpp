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

void Remote::init() {
	if (SDLNet_ResolveHost(ip, ipString.c_str(), port) == -1)
		net_error();

	if (!(socket = SDLNet_TCP_Open(ip)))
		net_error();
}

Remote::Remote(std::string newIP, Uint16 newPort) : Socket_Base(newIP, newPort) {
	port     = newPort;
	ipString = newIP;
	ip = new IPaddress();
	init();
}

Remote::~Remote() {
	delete(ip);
	close_socket();
}

//IP
void Remote::set_ip(std::string newIP) { 
	ipString = newIP;
	init();
}
