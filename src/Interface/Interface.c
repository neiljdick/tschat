#include "Interface.h"


#define BODY_DEF

/* I'm using global variables here to simplify the function interface, hopefully make calling this from other languages easier.  */

WINDOW *m_pWin = NULL;
THMutex_Type m_Lock; 
char Nick[32];


#include "INTInit.c"
#include "INTRead.c"
#include "INTWrite.c"
#include "INTDestroy.c"
