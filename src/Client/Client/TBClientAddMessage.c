/* Adds an announcement to the queue! */

void TBClientAddMessage(TBClient_Type *pClient_Arg, char *pMessage_Arg)
#ifdef BODYDEF
{
	assert(pClient_Arg);
	assert(pMessage_Arg);

	THQWrite(&pClient_Arg->TxQueue, pMessage_Arg);
	return;
}
#else
;
#endif
