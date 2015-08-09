/* Main Server Thread */

void TBServerRxFunc(TBServer_Type *pServer_Arg)
#ifdef BODYDEF
{
	assert(pServer_Arg);
	char pOtherNick[MAX_BODY_SIZE];
	TBServer_Type *this = pServer_Arg;


	/* Bind the server to the port */
	this->ServerBind(this->SrvSocket);
	printf("Socket Online \n");
	strcpy(pOtherNick,"Other");
	while(1)
	{
		TBMessage_Type *pMsg = malloc(sizeof(TBMessage_Type));
		assert(pMsg);
		this->ServerRead(this->SrvSocket, sizeof(TBMessage_Type), (char *)pMsg);
		switch(pMsg->Header.Type)
		{
		case MSG_TYPE_NICK:
			pMsg->Body[pMsg->Header.Length] = '\0';			
			strcpy(pOtherNick, pMsg->Body);
			break;

		case MSG_TYPE_CHAT:
			assert(pMsg->Header.Length < MAX_BODY_SIZE);
			pMsg->Body[pMsg->Header.Length] = '\0';
			INTWrite(pOtherNick, pMsg->Body);
			break;
		}
		free (pMsg);
	}
}
#else
;
#endif
