/* Write to UDP socket */

int NWUDPWriteSocket(NWUDPSocket* Socket_Arg, int NumBytes_Arg, char * Data_Arg)
#ifdef BODYDEF
{
	int Err;
	socklen_t Other = sizeof(struct sockaddr_in);
	assert(Data_Arg);
	assert(Socket_Arg);

	Err = sendto(Socket_Arg->UDPSocket, Data_Arg, NumBytes_Arg, 0, (struct sockaddr *)&Socket_Arg->Si_me, Other);
	if (Err == -1)
	{
		NWUDPSocketPerror("Write Socket");
		return -1;
	}
	return 0;
}
#else
;
#endif
