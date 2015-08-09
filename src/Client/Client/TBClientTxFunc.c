/* TX client thread.
   Reads from the Queue and sends it to the network.
*/
void *TBClientTxFunc(void *pClient_Arg)
#ifdef BODYDEF
{
	BOOL SentNick = FALSE;
	TBClient_Type *pThis = (TBClient_Type*)pClient_Arg;
	assert(pThis);
	while(pThis->Running)
	{
		char *pMsg = NULL;
		TBMessage_Type Msg;
		THQRead(&pThis->TxQueue, &pMsg);
		assert(pMsg);
		if (SentNick == FALSE)
		{
			Msg.Header.Type = MSG_TYPE_NICK;
			memcpy(Msg.Body,
				   pThis->Nick,
				   strlen(pThis->Nick));

			Msg.Header.Length = strlen(pThis->Nick);

			pThis->ClientWrite(pThis->CliSocket,
							   MSG_PACKET_LEN(Msg),
							   (char *)&Msg);			
			SentNick = TRUE;
		}
		Msg.Header.Type = MSG_TYPE_CHAT;
		memcpy(Msg.Body,
			   pMsg,
			   strlen(pMsg));

		Msg.Header.Length = strlen(pMsg);

		pThis->ClientWrite(pThis->CliSocket,
						   MSG_PACKET_LEN(Msg),
						   (char *)&Msg);			
		free(pMsg);
	}

	ThreadExit(NULL);
}
#else
;
#endif
