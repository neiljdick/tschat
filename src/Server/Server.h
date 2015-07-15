/* Game Server  */
#ifndef SERVER_H
#define SERVER_H

#include "Environment.h"
#include "Network/Network.h"
#include "Threads/Threads.h"

typedef NWUDPSocket ServerSocket;

typedef struct
{
	ServerSocket *SrvSocket;
	int (*ServerRead)(ServerSocket *pSocket_Arg, int Size_Arg, char *pBuf_Arg);
	int (*ServerWrite)(ServerSocket *pSocket_Arg, int Size_Arg, char *pBuf_Arg);
	int (*ServerBind)(ServerSocket *pSocket_Arg);
	THQueue RxQueue;
	THThread_Type RxThread;
	BOOL Running;
} TBServer_Type;

#include "Server/TBServerCreate.c"
#include "Server/TBServerRxFunc.c"
#include "Server/TBServerDestroy.c"

#endif