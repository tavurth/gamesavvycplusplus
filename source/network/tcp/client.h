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

#ifndef GSC_CLIENT
#define GSC_CLIENT

#include "../../headers/GSC.h"
#include "tcp.h"

namespace gsc {
	namespace tcp {
		class Client : public Socket_Base {
			private:
				SDL_Thread * thread;
				Host * parent;
				int flags;
			public:
				Client(TCPsocket newSocket, Host * newParent);
				Client();
				~Client();

				void kill();
				SDL_Thread * set_thread(SDL_Thread * newThread);
				SDL_Thread * get_thread() const;

				Host * get_parent() const;
		};
	}
}

#endif
