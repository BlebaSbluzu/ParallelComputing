#include <stdio.h>
#include <pthread.h>

void *mythread_func(void *param)
{
printf("In child thread code\n");
}

int main()
{
pthread_t mythread_handle;
pthread_create(&mythread_handle, NULL, &mythread_func, NULL);
 
printf("In the main thread\n");
 
pthread_join(mythread_handle, NULL);
return 0;
}
