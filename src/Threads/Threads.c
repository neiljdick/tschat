#include "Threads.h"
#define BODYDEF
#ifdef POSIX_ENV
#include "POSIX/MutexInit.c"
#include "POSIX/MutexDestroy.c"
#include "POSIX/MutexLock.c"
#include "POSIX/MutexUnlock.c"
#include "POSIX/ThreadCreate.c"
#include "POSIX/SemaphoreInit.c"
#include "POSIX/SemaphoreWait.c"
#include "POSIX/SemaphoreDestroy.c"
#include "POSIX/SemaphorePost.c"
#include "POSIX/ThreadDestroy.c"
#include "POSIX/SemGetValue.c"
#endif

/* Queue / Mailbox  */
#include "THQCreate.c"
#include "THQDestroy.c"
#include "THQWrite.c"
#include "THQRead.c"
#include "THQIsEmpty.c"
