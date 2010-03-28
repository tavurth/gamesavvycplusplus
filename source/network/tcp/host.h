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

#ifndef GSC_TCP_HOST
#define GSC_TCP_HOST

#include "../../headers/GSC.h"
#include "tcp.h"

namespace gsc {
	namespace tcp {
		class Host : public Socket_Base {
			private:
				host_function function;
				SDL_Thread * thread;
				Uint16 sleepDelay;
				int flags;
				std::vector<Client *> clientList;

				void init();
			public:
				Host(Uint16 newPort);
				~Host();

				void set_sleep_delay(Uint16 newDelay);
				Uint16 get_sleep_delay() const;

				void set_client_loop_function (host_function newFunction);
				host_function get_client_loop_function() const;

				int get_flags() const;
				void set_flags(int newFlags);

				std::vector<Client *> get_clients() const;
				void add_client(Client * newClient);
				void remove_client(Client * newClient);

				void set_ip(std::string newIP);
		};

		extern std::vector<Host *> hostList;
		void delete_all_hosts();
	}
}

#endif
