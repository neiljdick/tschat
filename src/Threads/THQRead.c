int THQRead(THQueue *pQueue_Arg, char  **ppBuf_Arg)
#ifdef BODYDEF
{
	assert(pQueue_Arg);
	assert(ppBuf_Arg);
	SemaphoreWait(&pQueue_Arg->Full);
	MutexLock(&pQueue_Arg->Lock);

	*ppBuf_Arg = pQueue_Arg->ppBuf[pQueue_Arg->Tail];
	pQueue_Arg->Tail = (pQueue_Arg->Tail+1) % pQueue_Arg->Size;

	MutexUnlock(&pQueue_Arg->Lock);
	SemaphorePost(&pQueue_Arg->Empty);
	return 0;
}
#else 
;
#endif
