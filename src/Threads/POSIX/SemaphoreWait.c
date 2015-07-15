void SemaphoreWait(THSemaphore_Type *pSem_Arg)
#ifdef BODYDEF
{
	sem_wait(pSem_Arg);
}
#else
;
#endif
