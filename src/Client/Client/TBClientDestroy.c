/* Destroy a created socket */


void TBClientDestroy(TBClient_Type *pClient_Arg)
#ifdef BODYDEF
{

	pClient_Arg->Running = FALSE;
	ThreadDestroy(&pClient_Arg->TxThread);
	THQDestroy(&pClient_Arg->TxQueue);
	NWUDPDestroySocket(pClient_Arg->CliSocket);	
}
#else
;
#endif
