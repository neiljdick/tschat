/* Creates the Server object  */

int TBServerCreate(TBServer_Type *pServer_Arg)
#ifdef BODYDEF
{
	pServer_Arg->SrvSocket = NWUDPCreateSocket(SERVER_PORT_NUM, NULL);
	assert(pServer_Arg->SrvSocket);
	pServer_Arg->ServerRead = NWUDPReadSocket;
	pServer_Arg->ServerWrite = NWUDPWriteSocket;
	pServer_Arg->ServerBind = NWUDPBindSocket;

	THQCreate(&pServer_Arg->RxQueue);
	pServer_Arg->Running = TRUE;
	ThreadCreate(&pServer_Arg->RxThread, (void *)pServer_Arg, TBServerRxFunc);
	return TRUE;
}
#else
;
#endif
