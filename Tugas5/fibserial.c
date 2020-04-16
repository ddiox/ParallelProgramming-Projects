#include <stdio.h>
#include <time.h>

int fib(int n){
	int x, y;
	if(n<2) return n;
	else{
		x = fib(n-1);
		y = fib(n-2);
		return x+y;
	}
}

int main(){
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
