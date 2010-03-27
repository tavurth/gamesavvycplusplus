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

void Socket_Base::init_ip() {
	ip = new IPaddress();
}

Socket_Base::Socket_Base() {
	init_ip();
	port     = 0;
	ipString = "localhost";
}

Socket_Base::Socket_Base(std::string newIP, short newPort) {
	init_ip();
	port     = newPort;
	ipString = newIP;
}

Socket_Base::Socket_Base(short newPort) {
	init_ip();
	port = newPort;
}

Socket_Base::~Socket_Base() {
	delete(ip);
}

//Port
void Socket_Base::set_port(Uint16 newPort) { 
	port = newPort; 
	init();
}

Uint16 Socket_Base::get_port() const { return port; }

void Socket_Base::close_socket() { SDLNet_TCP_Close(socket); }
TCPsocket Socket_Base::get_socket() const { return socket; }

IPaddress * Socket_Base::get_ip() const { return ip; }
std::string Socket_Base::get_ip_string() const { return ipString; }
