/* Comms Client Object  */
#ifndef CLIENT_H
#define CLIENT_H

#include "Network/Network.h"
#include "Threads/Threads.h"

typedef NWUDPSocket ClientSocket;

typedef struct
{
	ClientSocket *CliSocket;
	int (*ClientRead)(ClientSocket *pSocket_Arg, int Size_Arg, char *pBuf_Arg);
	int (*ClientWrite)(ClientSocket *pSocket_Arg, int Size_Arg, char *pBuf_Arg);
	THQueue TxQueue; 			/* Send Message */
	THThread_Type TxThread;
	BOOL Running;
	char *pNick;
} TBClient_Type;

#include "Client/TBClientCreate.c"
#include "Client/TBClientDestroy.c"
#include "Client/TBClientTxFunc.c"
#include "Client/TBClientAddMessage.c"

#endif