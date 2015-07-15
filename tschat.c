/* Trivial Secure chat! */

/* This program makes use of openssl to encrypt/decrypt messages
   
 */

#include "Environment.h"
#include <unistd.h>
#include "Client/Client.h"
#include "Server/Server.h"
#include "Network/Network.h"
#include <string.h>

void HandleCmdLine(int argc, char **argv);
void PrintHelp(void);

char *pNickName = NULL;
int main(int argc, char **argv)
{
	TBClient_Type Client;
	TBServer_Type Server;

	HandleCmdLine(argc, argv);

	TBClientCreate(&Client, pNickName);
	TBServerCreate(&Server);
	while(1)
	{
		char *pMsg = malloc(THQ_MESSAGE_SIZE);
		fgets(pMsg, THQ_MESSAGE_SIZE, stdin);
		TBClientAddMessage(&Client, pMsg);
	}

}

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
			SERVER_DESTINATION_ADDR = argv[i+1];
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

