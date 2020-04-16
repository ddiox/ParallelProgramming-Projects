#include<stdio.h> 
#include<math.h> 
#include<time.h>

int fib(int n) { 
  double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
} 

int main () 
{ 
  int n = 40; 
  int R = 0;
  long start, finish;
  double exec_time;
  
  start = clock();
  R = fib(n);
  printf("%d\n", R); 
  finish = clock();
  
  exec_time = (double) (finish-start)/CLOCKS_PER_SEC;
  printf("exec_time %1f\n", exec_time);
  
  return 0; 
} 


