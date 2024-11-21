#include <stdio.h>
#include <stdlib.h>

extern int thread_count;

void *child_hello(void *rank){
long my_rank = (long) rank;
 
printf("Hello from child thread %ld of a total of %d child threads\n", my_rank, thread_count);
}
