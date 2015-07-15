/* Creates a UDP socket  */
NWUDPSocket * NWUDPCreateSocket(unsigned int Port_Arg, char *Dest_Addr)
#ifdef BODYDEF
{

	/* Assign a socket structure */
	NWUDPSocket *Socket = (NWUDPSocket *) malloc(sizeof(NWUDPSocket));
	if(Socket == NULL)
	{
		EXCEPTION ErrAlloc;
	}
	memset((char *)Socket, 0, sizeof(NWUDPSocket));
	Socket->UDPSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(Socket->UDPSocket < 0)
	{
		NWUDPSocketPerror("Socket assign \n");
		goto ErrInit;
	}
	Socket->Si_me.sin_family = AF_INET;
	Socket->Si_me.sin_port = htons(Port_Arg);
	if(Dest_Addr == NULL)
	{
		Socket->Si_me.sin_addr.s_addr = htonl(INADDR_ANY);
	}
	else
	{
		inet_aton(Dest_Addr, &Socket->Si_me.sin_addr);
	}
	return Socket;

ErrInit:
	NWUDPDestroySocket(Socket);
ErrAlloc:
	NWUDPSocketPerror("Socket Malloc\n");
	return NULL;
}
#else
;
#endif
