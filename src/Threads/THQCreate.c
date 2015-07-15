/* Creates a queue */

int THQCreate(THQueue *pQueue_Arg)
#ifdef BODYDEF
{
	assert(pQueue_Arg);
	/* Allocate the buffer  */
	pQueue_Arg->ppBuf = malloc(sizeof(char *)*THQUEUE_SIZE);
	assert(pQueue_Arg);
	MutexInit(&pQueue_Arg->Lock);
	SemaphoreInit(&pQueue_Arg->Empty, THQUEUE_SIZE);
	SemaphoreInit(&pQueue_Arg->Full, 0);
	pQueue_Arg->Size = THQUEUE_SIZE;
	pQueue_Arg->Head = 0;
	pQueue_Arg->Tail = 0;


	return 0;
}
#else
;
#endif
