#include <stdio.h>
#include <omp.h>

void XAXIS();
void YAXIS();
void ZAXIS();

int main(){
	#pragma omp parallel sections
	{
    	#pragma omp section
    	{ 
        	XAXIS();
    	}

    	#pragma omp section
    	{ 
        	YAXIS();
    	}
    	
    	#pragma omp section
    	{ 
    		ZAXIS();
    	}
	}
}

void XAXIS (){
	printf ("XAXIS, id = %d\n", omp_get_thread_num());
}

void YAXIS (){
	printf ("YAXIS, id = %d\n", omp_get_thread_num());
}

void ZAXIS (){
	printf ("ZAXIS, id = %d\n", omp_get_thread_num());
}

