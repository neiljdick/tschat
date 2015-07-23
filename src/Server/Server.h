#ifndef SERVER_H
#define SERVER_H

#include "Environment.h"
#include "Network/Network.h"
#include "Threads/Threads.h"
#include "Interface/Interface.h"

#define TBSERVER_NICK_LEN 32
#define TBSERVER_BUF_SIZE 256

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
	char Nick[TBSERVER_NICK_LEN];
	char Msg[TBSERVER_BUF_SIZE];
} TBMessage_Type;

#include "Server/TBServerCreate.c"
#include "Server/TBServerRxFunc.c"
#include "Server/TBServerDestroy.c"

#endif
