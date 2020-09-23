#include <stdio.h>
#include <semaphore.h> //ADDED TO USE SEMAPHORES
#include <stdlib.h> //ADDED TO USE RAND()
#include <pthread.h> //ADDED TO USE THREADS
#include <unistd.h>
#define MAX_RESOURCES 5
const int stock_max_limit= MAX_RESOURCES;
int available_resources = 0;

sem_t sem_dec,sem_inc; //declaring a semaphore for the increase function and one for the decrease.


int decrease_count(int count) 
{
    
    if (available_resources < count)
        return -1;
    else {
        available_resources -= count;
         }
   
    return 0;
}

/* increase available resources by count */
int increase_count(int count)
{
    available_resources += count;
    return 0;
    
}
void *consumer(void *arg) 
{
    int i, x;
    for (i = 0; i < 10; i++) {
        x = rand()%4;
        while(0 == available_resources+x)
        {
            printf("Not enough ressources, consumer on wait..\n");
            sem_wait(&sem_inc);
            printf("consumer operation continues..\n");
        }

       sleep(1);   //consumer rate
        decrease_count(x);
        printf("Consumer:Stock %d\n", available_resources);
        sem_post(&sem_dec);
        printf("Consumer:post signal.Exited critical section\n");
        }

    
}

void *producer(void *arg) 
{
     int i, x;
    for (i = 0; i < 10; i++) {
        x = rand()%3;
        while(stock_max_limit == x+available_resources){
            printf("stock overflow, production on wait..\n");
            sem_wait(&sem_dec);
            printf("production operation continues..\n");
        }

        sleep(1);   //production rate
        increase_count(x);
        printf("Producer: Stock: %d\n",available_resources);
        sem_post(&sem_inc);
        printf("Producer::post signal.Exited critical section\n");
    }

    
}

int main ()
{
    pthread_t t1,t2;

    //initialising the semaphores
    sem_init(&sem_dec, 0, 0);
    sem_init(&sem_inc, 0, 0);

    //Do the work
    pthread_create(&t1, NULL, consumer, NULL);
    pthread_create(&t2, NULL, producer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    //Destroying the Semaphores
    sem_destroy(&sem_dec);
    sem_destroy(&sem_inc);

    return 0;
}
