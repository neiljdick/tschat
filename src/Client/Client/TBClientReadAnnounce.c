/* Attempts to read from the queue. If it is empty, just return */

int TBClientReadMessage(TBClient_Type *pClient_Arg, INTAnnounce_Type *pAnnounce_Arg)
#ifdef BODYDEF
{
	assert(pClient_Arg);
	if (THQIsEmpty(&pClient_Arg->RxQueue))
	{
		return -1;
	}
	else
	{
		THQRead(&pClient_Arg->RxQueue, pAnnounce_Arg);
		return 0;
	}
}
#else
;
#endif
