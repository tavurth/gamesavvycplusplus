#ifndef GSC_CLIENT
#define GSC_CLIENT

#include "../../headers/GSC.h"
#include "tcp.h"

namespace gsc {
	namespace tcp {
		class Client {
			private:
				TCPsocket socket;
				IPaddress * ip;
				SDL_Thread * thread;
				Host * parent;
			public:
				Client(TCPsocket newSocket, Host * newParent);
				~Client();

				TCPsocket get_socket() const;
				void set_socket(TCPsocket newSocket);

				IPaddress * get_ip() const;
				void set_ip(IPaddress * newIP);

				void kill();
				SDL_Thread * set_thread(SDL_Thread * newThread);
				SDL_Thread * get_thread() const;

				Host * get_parent() const;
		};
	}
}

#endif
