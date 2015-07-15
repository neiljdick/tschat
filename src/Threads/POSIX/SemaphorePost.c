void SemaphorePost(THSemaphore_Type *pSem_Arg)
#ifdef BODYDEF
{
	sem_post(pSem_Arg);
}
#else
;
#endif
