int INTRead(char *pBuf_Arg)
#ifdef BODY_DEF
{
	int Ret = 0;
	assert(pBuf_Arg);

	MutexLock(&m_Lock);
	move(LINES-2,0);
	clrtoeol();
	move(LINES-2,0);
	waddstr(stdscr,Nick);
	waddstr(stdscr,": ");
	wrefresh(m_pWin);
	refresh();
	MutexUnlock(&m_Lock);


	getnstr(pBuf_Arg, INT_BUF_SIZE);
	if (!strcmp(pBuf_Arg, "/quit"))
	{
		Ret = -1;
	}

	INTWrite(Nick, pBuf_Arg);


	return Ret;
}
#else
;
#endif
