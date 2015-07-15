void NWUDPSocketPerror(char *Err_Arg)
#ifdef BODYDEF
{
	perror(Err_Arg);
	assert(0);
}
#else
;
#endif
