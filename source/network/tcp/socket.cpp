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

Socket_Base::Socket_Base() {
	port     = 0;
	ipString = "localhost";
}

Socket_Base::Socket_Base(std::string newIP, short newPort) {
	port     = newPort;
	ipString = newIP;
}

Socket_Base::Socket_Base(short newPort) {
	port = newPort;
}

Socket_Base::~Socket_Base() {
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

//Send void data
void Socket_Base::send(void * data, int length) const {
	SDLNet_TCP_Send(socket, data, length);
}

//Send an integer
void Socket_Base::send (int to_send) const { 
	char data[sizeof(int)];
	SDLNet_Write32(to_send, data);
	send((void *)data, sizeof(int)); 
}

//Send a floating point
void Socket_Base::send (float to_send) const { 
	char data[sizeof(float)];
	SDLNet_Write32(*reinterpret_cast<long *>(&to_send), data);
	send((void *)data, sizeof(float)); 
}

//Send a double
void Socket_Base::send (double to_send) const {
	send((float) to_send);
}

//Send a string
void Socket_Base::send (std::string to_send) const { 
	send((int) to_send.length());
	send((void *)to_send.c_str(), to_send.length());
}

//Recieve an integer
int Socket_Base::recv_int() const {
	int result = 0;

	if (SDLNet_TCP_Recv(socket, &result, sizeof(int)) <= 0)
		net_error();

	result = SDLNet_Read32(&result);
	
	return result;
}

//Recieve a string
std::string Socket_Base::recv_str() const {
	int length = recv_int();

	char tempString[length];

	if (SDLNet_TCP_Recv(socket, tempString, length) <= 0)
		net_error();
	tempString[length] = '\0';
	
	return std::string(tempString);
}

//Recieve a floating point
float Socket_Base::recv_float() const {
	float to_return = 0.0;
	long temp = 0.0l;
	char data[sizeof(float)];

	if (SDLNet_TCP_Recv(socket, data, sizeof(float)) <= 0)
		net_error();

	temp = SDLNet_Read32(data);
	to_return = *reinterpret_cast<float *>(&temp);

	return to_return;
}
