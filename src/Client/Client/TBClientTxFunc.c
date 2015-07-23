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
		TBMessage_Type *pMsg = NULL;
		THQRead(&pThis->TxQueue, (char **)&pMsg);
		assert(pMsg);
		pThis->ClientWrite(pThis->CliSocket, sizeof(TBMessage_Type), (char *)pMsg);
		free(pMsg);
	}
	ThreadExit(NULL);
}
#else
;
#endif
