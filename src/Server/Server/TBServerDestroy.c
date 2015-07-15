/* Destroy a  created server object */

void TBServerDestroy(TBServer_Type *pServer_Arg)
#ifdef BODYDEF
{
	NWUDPDestroySocket(pServer_Arg->SrvSocket);
	pServer_Arg->Running = FALSE;
	ThreadDestroy(&pServer_Arg->RxThread);
	THQDestroy(&pServer_Arg->RxQueue);
}
#else
;
#endif
