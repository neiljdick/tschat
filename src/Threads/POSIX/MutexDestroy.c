int MutexDestroy(THMutex_Type *pMutex_Arg)
#ifdef BODYDEF
{

	return pthread_mutex_destroy(pMutex_Arg);

}
#else
;
#endif
