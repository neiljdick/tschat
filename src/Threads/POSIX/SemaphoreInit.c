void SemaphoreInit(THSemaphore_Type *pSem_Arg, unsigned int value)
#ifdef BODYDEF
{
	sem_init(pSem_Arg, 0, value);

}
#else
;
#endif
