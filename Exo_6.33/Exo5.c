#include <stdio.h>
#include <semaphore.h> //ADDED TO USE SEMAPHORES


#define MAX_RESOURCES 5
int available_resources = MAX_RESOURCES;

sem_t sem_dec,sem_inc; //declaring a semaphore for the increase function and one for the decrease.

/* decrease available resources by count resources */
/* return 0 if sufficient resources available, */
/* otherwise return -1 */

int decrease_count(int count) 
{
    sem_wait(&sem_inc); //We need to lock access to the available_resources variabale so it 
                      // does not get modified while we're using it
    
    //critical section
    printf("Entering critical section");
    if (available_resources < count)
        return -1;
    else {
        available_resources -= count;
         }
    printf("Exiting critical section");

    sem_post(&sem_dec); //releasing 
    return 0;
}

/* increase available resources by count */
int increase_count(int count)
{
    sem_wait(&sem_dec);
    //critical section
    printf("Entering critical section");

    available_resources += count;

    printf("Exiting critical section");
    sem_post(&sem_inc); //Release
    return 0;
    
}

int main ()
{
    //initialising the semaphores
    sem_init(&sem_dec, 0, 0);
    sem_init(&sem_inc, 0, 0);

    //Do the work

    //Destroying the Semaphores
    sem_destroy(&sem_dec);
    sem_destroy(&sem_inc);

    return 0;
}