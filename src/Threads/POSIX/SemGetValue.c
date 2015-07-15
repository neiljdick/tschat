int SemGetValue(THSemaphore_Type *pSem_Arg)
#ifdef BODYDEF
{
	int Val;
	sem_getvalue(pSem_Arg, &Val);
	return Val;
}
#else
;
#endif
