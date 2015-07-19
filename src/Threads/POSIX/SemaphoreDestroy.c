int SemaphoreDestroy(THSemaphore_Type *pSem_Arg)
	#ifdef BODYDEF
{
	assert(pSem_Arg);
	return sem_destroy(pSem_Arg);
}
#else
;
#endif
