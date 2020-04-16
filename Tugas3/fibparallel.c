#include <stdio.h>
#include <time.h>
#include <omp.h>

int n = 40;
int R = 0;

int fib(int n){
	int x, y;
	if(n<2) return n;
	else{
		#pragma omp task shared(x) if(n>20)
		x = fib(n-1);
		
		y = fib(n-2);
		
		#pragma omp taskwait
		return x+y;
	}
}

int main(){
	
	long start, finish;
	double exec_time;
	
	start = clock();
	#pragma omp parallel 
	{
		#pragma omp single
		R = fib(n);
	}
	
	printf("%d\n", R);
	finish = clock();
	
	exec_time = (double) (finish-start)/CLOCKS_PER_SEC;
	printf("exec_time %1f\n", exec_time);
	
	return 0;
}
