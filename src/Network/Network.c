#include "Network.h"

#ifdef POSIX_ENV

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define _BSD_SOURCE
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>


#define BODYDEF
#include "NWUDPCreateSocket.c"
#include "NWUDPWriteSocket.c"
#include "NWUDPReadSocket.c"
#include "NWUDPBindSocket.c"
#include "NWUDPDestroySocket.c"
#include "NWUDPSocketPerror.c"

#endif
