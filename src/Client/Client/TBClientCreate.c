/* Creates a client object */

int TBClientCreate(TBClient_Type *pClient_Arg, char *pNick_Arg)
#ifdef BODYDEF
{
	pClient_Arg->CliSocket = NWUDPCreateSocket(SERVER_PORT_NUM, SERVER_DESTINATION_ADDR);
	assert(pClient_Arg->CliSocket);
	pClient_Arg->pNick = pNick_Arg;
	pClient_Arg->ClientRead = NWUDPReadSocket;
	pClient_Arg->ClientWrite = NWUDPWriteSocket;

	/* Create syncronized queues for RX and TX */
	THQCreate(&pClient_Arg->TxQueue);

	pClient_Arg->Running = TRUE;
	/* Create the TX Thread */
	ThreadCreate(&pClient_Arg->TxThread,(void *)pClient_Arg,TBClientTxFunc);

	return TRUE;
}
#else
;
#endif
