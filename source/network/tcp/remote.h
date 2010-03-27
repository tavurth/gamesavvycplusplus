#ifndef GSC_TCP_REMOTE
#define GSC_TCP_REMOTE

#include "../../headers/GSC.h"
#include "client.h"

namespace gsc {
	namespace tcp {
		class Remote {
			private:
				IPaddress ip;
				Uint16 port;
				TCPsocket socket;
				std::string ipString;

				void init();
			public:
				Remote(std::string newIP, Uint16 newPort);
				~Remote();

				void set_port(Uint16 newPort);
				Uint16 get_port() const;

				TCPsocket get_socket() const;
				void close_socket();

				void set_ip(std::string newIP);
				IPaddress get_ip() const;
				std::string get_ip_string() const;
		};
	}
}

#endif
