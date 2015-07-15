/* Destroy a created socket  */

void NWUDPDestroySocket(NWUDPSocket* Socket_Arg)
#ifdef BODYDEF
{
	if(Socket_Arg)
	{
		free(Socket_Arg);
		Socket_Arg = NULL;
	}
	return;
}
#else
;
#endif
