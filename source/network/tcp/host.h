#ifndef GSC_TCP_HOST
#define GSC_TCP_HOST

#include "../../headers/GSC.h"
#include "tcp.h"

namespace gsc {
	namespace tcp {
		class Host {
			private:
				Uint16 port;
				TCPsocket socket;
				IPaddress ip;
				host_function function;
				SDL_Thread * thread;
				Uint16 sleepDelay;
				int flags;
				std::vector<Client *> clientList;

				void init();
				void close_socket();
			public:
				Host(Uint16 newPort);
				~Host();

				void set_port(Uint16 newPort);
				Uint16 get_port() const;

				TCPsocket get_socket() const;

				void set_sleep_delay(Uint16 newDelay);
				Uint16 get_sleep_delay() const;

				void set_function (host_function newFunction);
				host_function get_function() const;

				int get_flags() const;
				void set_flags(int newFlags);

				std::vector<Client *> get_clients() const;
				void add_client(Client * newClient);
		};

		int host_loop(void *);
	}
}

#endif
