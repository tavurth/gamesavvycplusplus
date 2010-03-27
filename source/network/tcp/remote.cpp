#include "../../headers/GSC.h"

using namespace gsc;
using namespace tcp;

void Remote::init() {
	if (SDLNet_ResolveHost(&ip, ipString.c_str(), port) == -1)
		net_error();

	if (!(socket = SDLNet_TCP_Open(&ip)))
		net_error();
}

Remote::Remote(std::string newIP, Uint16 newPort) {
	port     = newPort;
	ipString = newIP;
	init();
}

Remote::~Remote() {
	close_socket();
}

//IP
void Remote::set_ip(std::string newIP) { 
	ipString = newIP;
	init();
}

IPaddress Remote::get_ip() const { return ip; }
std::string Remote::get_ip_string() const { return ipString; }

//Port
void Remote::set_port(Uint16 newPort) { 
	port = newPort; 
	init();
}

Uint16 Remote::get_port() const { return port; }

void Remote::close_socket() { SDLNet_TCP_Close(socket); }
TCPsocket Remote::get_socket() const { return socket; }
