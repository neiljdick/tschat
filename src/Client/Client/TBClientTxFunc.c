/* TX client thread.
   Reads from the Queue and sends it to the network.
 */
void *TBClientTxFunc(void *pClient_Arg)
#ifdef BODYDEF
{
	TBClient_Type *pThis = (TBClient_Type*)pClient_Arg;
	assert(pThis);
	while(pThis->Running)
	{
		char *pMsg = NULL;
		THQRead(&pThis->TxQueue, &pMsg);
		assert(pMsg);
		pThis->ClientWrite(pThis->CliSocket, THQ_MESSAGE_SIZE, pMsg);
		printf("\n %s: %s\n", pThis->pNick, pMsg);
		free(pMsg);
	}
	ThreadExit(NULL);
}
#else
;
#endif
