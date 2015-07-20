
/* Reads from a UDP socket */



int NWUDPReadSocket(NWUDPSocket *Socket_Arg, int Size_Arg, char *Buf_Arg)
#ifdef BODYDEF
{
	int Err;
	socklen_t Other = sizeof(struct sockaddr_in);
	Err = recvfrom(Socket_Arg->UDPSocket,
				   Buf_Arg,
				   Size_Arg,
				   0,
				   (struct sockaddr *) &Socket_Arg->Si_me,
				   &Other);
	if (Err == -1)
	{
		NWUDPSocketPerror("Recvfrom");
		return -1;
	}
	return 0;
}
#else
;
#endif
