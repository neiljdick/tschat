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
		char *pMsg = malloc(THQ_MESSAGE_SIZE);
		assert(pMsg);
		this->ServerRead(this->SrvSocket, THQ_MESSAGE_SIZE, pMsg);
		INTWrite(OtherNick, pMsg);
		free (pMsg);
//		THQWrite(&this->RxQueue, pMsg);
	}
}
#else
;
#endif
