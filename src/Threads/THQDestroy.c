void THQDestroy(THQueue *pQueue_Arg)
#ifdef BODYDEF
{
	assert(pQueue_Arg);
	assert(pQueue_Arg->ppBuf);
	for (int i = pQueue_Arg->Tail; i != pQueue_Arg->Head; i = ((i+1)%pQueue_Arg->Size))
	{
		free(pQueue_Arg->ppBuf[i]);
	}
	free(pQueue_Arg->ppBuf);
	MutexDestroy(&pQueue_Arg->Lock);
	SemaphoreDestroy(&pQueue_Arg->Empty);
	SemaphoreDestroy(&pQueue_Arg->Full);
}
#else 
;
#endif
