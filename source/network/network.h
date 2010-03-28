#ifndef GSC_NETWORK
#define GSC_NETWORK

#include "../headers/GSC.h"
#include "../network/tcp/socket.h"
#include "../network/tcp/tcp.h"
#include "../network/tcp/client.h"
#include "../network/tcp/host.h"
#include "../network/tcp/remote.h"

namespace gsc {
	void network_delete_all();
}

#endif
