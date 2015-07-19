/* Threading Library.
   Provide wrappers around posix threads for now.
*/
#ifndef THREADS_H
#define THREADS_H
#include "Environment.h"

#ifdef POSIX_ENV

#include <pthread.h>
#include <semaphore.h>
typedef pthread_mutex_t THMutex_Type;
typedef pthread_t THThread_Type;
typedef sem_t THSemaphore_Type;

#include "POSIX/MutexInit.c"
#include "POSIX/MutexDestroy.c"
#include "POSIX/MutexLock.c"
#include "POSIX/MutexUnlock.c"
#include "POSIX/ThreadCreate.c"
#include "POSIX/SemaphoreInit.c"
#include "POSIX/SemaphoreDestroy.c"
#include "POSIX/SemaphoreWait.c"
#include "POSIX/SemaphorePost.c"
#include "POSIX/ThreadDestroy.c"
#include "POSIX/SemGetValue.c"
#define ThreadExit(pArg) \
	pthread_exit(pArg)
#endif

#define THQUEUE_SIZE 10
#define THQ_MESSAGE_SIZE 256
typedef struct
{
	THSemaphore_Type Empty;
	THSemaphore_Type Full;
	THMutex_Type Lock;
	char **ppBuf;
	int Size;
	int Head;
	int Tail;
}THQueue;

#include "THQCreate.c"
#include "THQDestroy.c"
#include "THQWrite.c"
#include "THQRead.c"
#include "THQIsEmpty.c"


#endif
