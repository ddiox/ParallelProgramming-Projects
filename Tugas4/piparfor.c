#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

long long num_steps = 1000000000;
double step;

int main () {
	int i;
	double exec_t, x, pi, sum = 0.0;
	long start, finish;
	
	start = clock();
	step = 1.0/(double) num_steps;
	#pragma omp parallel num_threads(4)
	{
		#pragma omp for  schedule(static)
		for(i=0;i<num_steps;i++)
		{
			x = (i+0.5)*step;
			#pragma omp critical
			sum += 4.0/(1.0+x*x); // terjadi race condition
		}
	}
	pi = step *sum;
	finish = clock();
	exec_t = (double) (finish - start)/CLOCKS_PER_SEC;
	
	printf("nilai pi %1f\n", pi);
	printf("exec_t %1f\n", exec_t);
	
	return 0;
}
