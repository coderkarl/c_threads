#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//http://randu.org/tutorials/threads/
//http://gribblelab.org/CBootcamp/A2_Parallel_Programming_in_C.html
// -pthread is needed during compile

#define NTHREADS 10

void *myFun(void *x)
{
	int tid;
	tid = *((int *) x);
	int k,n;
	n = 1;//(tid % 2)*5 + 1;
	if(tid == 0){n=10;}
	for (k = 0; k<n; k++)
	{
		printf("This is thread %d\n",tid);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t threads[NTHREADS];
	int thread_args[NTHREADS];
	int rc, i,j,y;
	
	// start the threads
	for (i=0; i<NTHREADS; i++)
	{
		thread_args[i] = i;
		printf("Starting thread %d\n",i);
		rc = pthread_create(&threads[i], NULL, myFun, (void *) &thread_args[i]);
		for (j=0;j<1000;j++){y = j*2+j*j;}
	}
	
	//wait for threads to finish
	for (i=0; i<NTHREADS; i++)
	{
		rc = pthread_join(threads[i],NULL);
	}
	return 0;
}
