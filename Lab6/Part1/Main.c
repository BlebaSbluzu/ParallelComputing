#include "timer.h"
 

int main() {
  double start, finish, elapsed;

  GET_TIME(start);


  elapsed = finish - start;
  printf("main: Time taken = %if seconds\n" ,elapsed);
  return 0;
}
