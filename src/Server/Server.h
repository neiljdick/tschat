#ifndef SERVER_H
#define SERVER_H

#include "Environment.h"
#include "Network/Network.h"
#include "Threads/Threads.h"
#include "Interface/Interface.h"

#define MAX_BODY_SIZE 512
#define MSG_PACKET_LEN(Packet) \
	(strlen(Packet.Body) + sizeof(TBMessageHeader_Type))

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

typedef enum
{
	MSG_TYPE_NICK,
	MSG_TYPE_CHAT
} MSG_TYPE_ENUM;

typedef struct
{
	uint32_t Type;
	uint32_t Length;
} TBMessageHeader_Type;
typedef struct
{
	TBMessageHeader_Type Header;
	char Body[MAX_BODY_SIZE];
} TBMessage_Type;

#include "Server/TBServerCreate.c"
#include "Server/TBServerRxFunc.c"
#include "Server/TBServerDestroy.c"

#endif
