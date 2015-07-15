/* Wrapper for posix mutex init */

void MutexInit(THMutex_Type *pMutex_Arg)
#ifdef BODYDEF
{
	assert(pMutex_Arg);
	/* What are errors? */
	/* TODO - Pass return values up chain */
	pthread_mutex_init(pMutex_Arg, NULL);
}
#else
;
#endif
