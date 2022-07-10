#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX 2
#define BUFFER 2

sem_t empty,full;
pthread_mutex_t mutex;
int in=0,out=0,buffer[BUFFER],i,m;

void *producer(void *pno){
	m =rand();
	for(i=0;i<MAX;i++){
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in] = m;
		printf("\n ATM holder %d request transaction, and ID %d generated.",in,m);
		in = (in + 1)% BUFFER;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

void *consumer(void *cno){
	for(i=0;i<MAX;i++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		m = buffer[out];
		printf("\n Bank server %d store data with ID %d.",out,m);
		out = (out+ 1)% BUFFER;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

void main(){
	pthread_t pro[MAX],con[MAX];
	pthread_mutex_init(&mutex,NULL);
	sem_init(&empty,0,BUFFER);
	sem_init(&full,0,0);
	int a[2] = {1,2};
	for(i=0;i<MAX;i++){
		pthread_create(&pro[i],NULL,(void*)producer,(void *)&a[i]);
	}
	for(i=0;i<MAX;i++){
		pthread_create(&con[i],NULL,(void*)consumer,(void *)&a[i]);
	}
	for(i=0;i<MAX;i++){
		pthread_join(pro[i],NULL);
	}
	for(i=0;i<MAX;i++){
		pthread_join(con[i],NULL);
	}
	sem_destroy(&empty);
	sem_destroy(&full);
	pthread_mutex_destroy(&mutex);

}
