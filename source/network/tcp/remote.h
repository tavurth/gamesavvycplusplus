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

#ifndef GSC_TCP_REMOTE
#define GSC_TCP_REMOTE

#include "../../headers/GSC.h"
#include "tcp.h"

namespace gsc {
	namespace tcp {
		class Remote : public Socket_Base {
			private:
				std::string ipString;

				void init();
			public:
				Remote(std::string newIP, Uint16 newPort);
				~Remote();

				void set_ip(std::string newIP);
		};
	}
}

#endif
