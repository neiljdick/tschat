BOOL THQIsEmpty(THQueue *pQueue_Arg)
#ifdef BODYDEF
{

	int Full = SemGetValue(&pQueue_Arg->Full);
	return (Full ? FALSE : TRUE);
}
#else 
;
#endif
