/*
	Example: race condition
	compile: gcc 1_race_condition.c -o race_condition -lpthread
	To execute: ./raceCondition
*/

#include <stdio.h>
#include <pthread.h>
#define NUMTHREADS 1000

/* Global variables - shared between threads */
double counter = 0;
/* Declaring functions*/
void* counting(void *);
 
int main(void) {
	pthread_t tid[NUMTHREADS];
	int i=0;
	
	for( i=0; i<NUMTHREADS; i++){
 		pthread_create (&tid[i], NULL, &counting, NULL);
 	}
 	
	for( i=0; i< NUMTHREADS; i++){
		pthread_join(tid[i], NULL);
	}
	
	printf("\nCounter value is: %.0f\n\n", counter);

	return 0;
}

/* Function Thread*/
void* counting(void * unused) {
	int i=0;
	for(i=0; i<1000; i++)
 		counter++;

	return NULL;
}
