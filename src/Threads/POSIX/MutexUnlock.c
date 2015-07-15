

void MutexUnlock(THMutex_Type *pMutex_Arg)
#ifdef BODYDEF
{
	assert(pMutex_Arg);
	pthread_mutex_unlock(pMutex_Arg);
}
#else
;
#endif
