/* Adds an announcement to the queue! */

void TBClientAddMessage(TBClient_Type *pClient_Arg, TBMessage_Type *pMessage_Arg)
#ifdef BODYDEF
{
	assert(pClient_Arg);
	assert(pMessage_Arg);
	strncpy(pMessage_Arg->Nick, pClient_Arg->Nick, sizeof(pMessage_Arg->Nick));
	THQWrite(&pClient_Arg->TxQueue, (char *)pMessage_Arg);
	return;
}
#else
;
#endif
