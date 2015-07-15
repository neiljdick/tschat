/* Wrapper around pthread_cancel */

void ThreadDestroy(THThread_Type *pThread_Arg)
#ifdef BODYDEF
{
	pthread_cancel(*pThread_Arg);

}
#else
;
#endif
