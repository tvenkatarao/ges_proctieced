#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
void *fun();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

int main()
{
	int rc1,rc2;
	pthread_t thread1,thread2 ;
	/* Create independent threads each of which will execute functionC */
	if((rc1 = pthread_create(&thread1,NULL,&fun,NULL)))
	{
		printf("thread creation faild:%d\n",rc1);

	}
	if((rc2 = pthread_create(&thread2,NULL,&fun,NULL)))
	{
		printf("thread creation failed :%d\n",rc2);
	}

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	exit(0);


}

void *fun()
{
	pthread_mutex_lock(&mutex1);
	count++;
	printf("counter value:%d\n",count);
	pthread_mutex_unlock(&mutex1);
}


