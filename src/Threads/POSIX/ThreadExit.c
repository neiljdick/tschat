void ThreadExit(void *pArg)
#ifdef BODYDEF
{
	pthread_exit(pArg);
}
#else
;
#endif
