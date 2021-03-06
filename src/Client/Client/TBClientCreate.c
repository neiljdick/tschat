/* Creates a client object */

int TBClientCreate(TBClient_Type *pClient_Arg, char *pNick_Arg, char *pDest_Arg)
#ifdef BODYDEF
{
	assert(pNick_Arg);
	assert(pDest_Arg);
	assert(pClient_Arg);

	pClient_Arg->pDestinationAddr = pDest_Arg;
	pClient_Arg->CliSocket = NWUDPCreateSocket(SERVER_PORT_NUM, pDest_Arg);
	assert(pClient_Arg->CliSocket);
	strncpy(pClient_Arg->Nick, pNick_Arg, sizeof(pClient_Arg->Nick));
	pClient_Arg->ClientRead = NWUDPReadSocket;
	pClient_Arg->ClientWrite = NWUDPWriteSocket;

	/* Create syncronized queues for TX */
	THQCreate(&pClient_Arg->TxQueue);

	pClient_Arg->Running = TRUE;
	/* Create the TX Thread */
	ThreadCreate(&pClient_Arg->TxThread, (void *)pClient_Arg, TBClientTxFunc);

	return TRUE;
}
#else
;
#endif
