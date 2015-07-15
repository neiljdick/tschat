/* Bind socket  */


int NWUDPBindSocket(NWUDPSocket *Socket_Arg)
#ifdef BODYDEF
{
	if(Socket_Arg == NULL)
	{
		return -1;
	}

	if(-1 == bind(Socket_Arg->UDPSocket, (struct sockaddr *)&Socket_Arg->Si_me, sizeof(Socket_Arg->Si_me)))
	{
		NWUDPSocketPerror("Bind");
		goto ErrBind;
	}
	return 0;
ErrBind:
	return -1;
}
#else
;
#endif
