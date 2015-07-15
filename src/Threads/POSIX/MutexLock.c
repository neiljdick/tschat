/* Wrapper for posix mutex functions  */

void MutexLock(THMutex_Type *pMutex_Arg)
#ifdef BODYDEF
{
	assert(pMutex_Arg);
	pthread_mutex_lock(pMutex_Arg);
}
#else
;
#endif
