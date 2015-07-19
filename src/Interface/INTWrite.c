void INTWrite(char *pNick_Arg, char *pBuf_Arg)
#ifdef BODY_DEF
{
	assert(pNick_Arg);
	assert(pBuf_Arg);

	/* Mutex lock needed to serialize writes to screen */
	MutexLock(&m_Lock);

	waddstr(m_pWin, pNick_Arg);
	waddstr(m_pWin, ": ");
	waddstr(m_pWin, pBuf_Arg);
	waddstr(m_pWin, "\n");
	wrefresh(m_pWin);
	refresh();
	MutexUnlock(&m_Lock);

	return;
}
#else
;
#endif
