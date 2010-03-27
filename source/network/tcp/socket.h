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

#ifndef GSC_SOCKET
#define GSC_SOCKET

#include "../../headers/GSC.h"

namespace gsc {
	namespace tcp {
		class Socket_Base {
			protected:
				IPaddress * ip;
				std::string ipString;
				Uint16 port;
				TCPsocket socket;

				void init_ip();
			public:
				Socket_Base();
				Socket_Base(short newPort);
				Socket_Base(std::string newIP, short newPort);
				~Socket_Base();

				TCPsocket get_socket() const;
				void close_socket();

				void set_port(Uint16 newPort);
				Uint16 get_port() const;

				IPaddress * get_ip() const;
				std::string get_ip_string() const;
		};
	}
}

#endif
