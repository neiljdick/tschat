/* Trivial insecure chat! */


#include "Environment.h"
#include <unistd.h>
#include "Client/Client.h"
#include "Server/Server.h"
#include "Network/Network.h"
#include "Interface/Interface.h"
#include <string.h>

void HandleCmdLine(int argc, char **argv);
void PrintHelp(void);

char *pNickName = NULL;
char *pDestination = NULL;

int main(int argc, char **argv)
{
	TBClient_Type Client;
	TBServer_Type Server;


	HandleCmdLine(argc, argv);

	/* Create the client and server objects */
	TBClientCreate(&Client, pNickName, pDestination);
	TBServerCreate(&Server);

	/* Initialize the curses interface */
	INTInit(pNickName);

	while(TRUE)
	{
		TBMessage_Type *pNwkMsg = malloc(sizeof(TBMessage_Type)); /* This gets free'd by the queue */
		memset(pNwkMsg, 0, sizeof(TBMessage_Type));
		/* Read a line of user input and pass it through the queue
		   to the socket thread
		 */
		if (INTRead(pNwkMsg->Msg, sizeof(pNwkMsg->Msg)) == -1)
		{
			/* user typed /quit */
			break;
		}
		TBClientAddMessage(&Client, pNwkMsg);
	}
	TBClientDestroy(&Client);
	TBServerDestroy(&Server);
	INTDestroy();

	return 0;
}


/* Quick and dirty command line handling. */
void HandleCmdLine(int argc, char **argv)
{
	if (argc != 5)
	{
		PrintHelp();
		exit(1);
	}	   

	for (int i=1; i < 4; i++)
	{
		if (0 == strcmp(argv[i], "-a"))
		{
			pDestination = argv[i+1];
		}
		else if (0 == strcmp(argv[i], "-n"))
		{
			pNickName = argv[i+1];
		}
		else
		{
			PrintHelp();
		}
	}
}


void PrintHelp(void)
{
	printf("Usage: ./tschat -a [address] -n [nickname] \nEg ./tschat -a 192.168.1.1 -n Neil \n");

}

