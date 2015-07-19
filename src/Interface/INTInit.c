void INTInit(char *pNick_Arg)
#ifdef BODY_DEF
{
	initscr();/* Start curses mode */

	int height = LINES-4;
	int width = COLS-1;
	int starty = 1;/* Calculating for a center placement */
	int startx = 1;/* of the window*/

	refresh();
	m_pWin = newwin(height, width, starty, startx);
	idlok(m_pWin, 1);
	scrollok(m_pWin, 1);
	move(LINES-2, 1);
	strncpy(Nick, pNick_Arg, sizeof(Nick));
	wrefresh(m_pWin);

	
	/* Initialize a mutex object to protect writes to window */
	MutexInit(&m_Lock);

	return;
}
#else
;
#endif
