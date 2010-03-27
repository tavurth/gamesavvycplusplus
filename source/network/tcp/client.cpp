#include "../../headers/GSC.h"

using namespace gsc;
using namespace tcp;

tcp::Client::Client(TCPsocket newSocket, Host * newParent) {
	socket = newSocket;
	parent = newParent;
	if (!(ip = SDLNet_TCP_GetPeerAddress(newSocket)))
		net_error();
}

tcp::Client::~Client() {
}
        
TCPsocket tcp::Client::get_socket() const { return socket; }
void   	  tcp::Client::set_socket(TCPsocket newSocket) { socket = newSocket; }
        
IPaddress * tcp::Client::get_ip() const { return ip; }
void        tcp::Client::set_ip(IPaddress * newIP) { ip = newIP; }

void tcp::Client::kill() {
	SDL_KillThread(thread);
}

SDL_Thread * tcp::Client::set_thread(SDL_Thread * newThread) { thread = newThread; return thread; }
SDL_Thread * tcp::Client::get_thread() const { return thread; }

Host * tcp::Client::get_parent() const { return parent; }
