/* Platform Specific Networking Code  */

#ifndef Networking_h
#define Networking_h
#include "Environment.h"

#define SERVER_PORT_NUM 6123

#ifdef POSIX_ENV
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct
{
	int UDPSocket;
	struct sockaddr_in Si_me;
	int Slen_Other;
}NWUDPSocket;


#include "NWUDPCreateSocket.c"
#include "NWUDPWriteSocket.c"
#include "NWUDPReadSocket.c"
#include "NWUDPBindSocket.c"
#include "NWUDPDestroySocket.c"
#include "NWUDPSocketPerror.c"

#endif
#endif
