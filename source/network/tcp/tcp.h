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

#ifndef GSC_TCP
#define GSC_TCP

#include "../../headers/GSC.h"

namespace gsc {
	namespace tcp {
		class Socket_Base;
		class Client;
		class Host;
		class Remote;

		typedef void (*host_function)(Client *);
		extern const int IS_ACTIVE;

		int host_loop(void *);
		int client_begin(Client * newClient);
	}
}

#endif
