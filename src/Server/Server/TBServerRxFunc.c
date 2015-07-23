/* Main Server Thread */

void TBServerRxFunc(TBServer_Type *pServer_Arg)
#ifdef BODYDEF
{
	assert(pServer_Arg);
	TBServer_Type *this = pServer_Arg;


	/* Bind the server to the port */
	this->ServerBind(this->SrvSocket);
	printf("Socket Online \n");
	while(1)
	{
		TBMessage_Type *pMsg = malloc(sizeof(TBMessage_Type));
		assert(pMsg);
		this->ServerRead(this->SrvSocket, sizeof(TBMessage_Type), (char *)pMsg);
		INTWrite(pMsg->Nick, pMsg->Msg);
		free (pMsg);
	}
}
#else
;
#endif
