#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NTHREADS 10
void *thread_fun(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int count =0;

int main()
{
	pthread_t thread_id[NTHREADS];
	int j,i;

	// thread creation
	for(i=0 ; i<NTHREADS; i++)
	{
		pthread_create(&thread_id[i],NULL,thread_fun,NULL);
	}

	// thread  join
	for(j=0 ; j< NTHREADS ; j++)
	{
		pthread_join(thread_id[j],NULL);
	}

	printf("final counter value:%d\n",count);
}
void *thread_fun(void *dummyptr)
{
	printf("thread number %ld\n",pthread_self());
	pthread_mutex_lock(&mutex1);
	count++;
	pthread_mutex_unlock(&mutex1);

}

