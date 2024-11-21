#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "myheader.h"
int main()
{
long thread;
 pthread_t *thread_handles;
 thread_handles = malloc (thread_count*sizeof(pthread_t));

 for (thread = 0; thread < thread_count; thread++)
pthread_create(&thread_handles[thread], NULL, child_hello, (void *) thread);
printf("Hello from the main thread\n");
for (thread = 0; thread < thread_count; thread++)
  pthread_join(thread_handles[thread], NULL);
 free(thread_handles);
return 0;
}
