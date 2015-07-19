void INTDestroy(void)
#ifdef BODY_DEF
{
	delwin(m_pWin);
	endwin();/* End curses mode  */
	MutexDestroy(&m_Lock);
}
#else
;
#endif
