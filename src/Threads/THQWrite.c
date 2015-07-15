int THQWrite(THQueue *pQueue_Arg, char *pMessage_Arg)
#ifdef BODYDEF
{
	assert(pQueue_Arg);
	assert(pMessage_Arg);
	SemaphoreWait(&pQueue_Arg->Empty);
	MutexLock(&pQueue_Arg->Lock);

	pQueue_Arg->ppBuf[pQueue_Arg->Head] =  pMessage_Arg;
	pQueue_Arg->Head = (pQueue_Arg->Head+1) % pQueue_Arg->Size;
	
	MutexUnlock(&pQueue_Arg->Lock);
	SemaphorePost(&pQueue_Arg->Full);
	return 0;
}
#else 
;
#endif
