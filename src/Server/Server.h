#ifndef SERVER_H
#define SERVER_H

#include "Environment.h"
#include "Network/Network.h"
#include "Threads/Threads.h"
#include "Interface/Interface.h"

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

typedef struct
{
	char Nick[32];
	char Msg[256];
} TBMessage_Type;

#include "Server/TBServerCreate.c"
#include "Server/TBServerRxFunc.c"
#include "Server/TBServerDestroy.c"

#endif
