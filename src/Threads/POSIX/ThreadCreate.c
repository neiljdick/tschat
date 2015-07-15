/* Creates a thread :0 */


void ThreadCreate(THThread_Type *pThread_Arg, void *pContext_Arg, void *pFunction_Arg)
#ifdef BODYDEF
{
	assert(pThread_Arg);
	assert(pFunction_Arg);
	assert(pContext_Arg);
	pthread_create(pThread_Arg, NULL, pFunction_Arg, pContext_Arg);
}
#else
;
#endif
