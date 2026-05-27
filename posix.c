#include <pthread.h>   
#include <stdio.h>
#include <stdlib.h>

int sum; /* this data is shared by the thread(s) */

void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
    pthread_t tid;           // Thread identifier 
    pthread_attr_t attr;     // Thread attributes structure 

    /* Set the default attributes of the thread */
    pthread_attr_init(&attr);   

    /* Create the thread */
    pthread_create(&tid, &attr, runner, argv[1]); 
    // The new thread will execute runner(argv[1])

    /* Wait for the thread to exit */
    pthread_join(tid, NULL);  
    // Main thread blocks until the spawned thread finishes

    printf("sum = %d\n", sum); // Print the final sum computed by the thread
    return 0;
}

/* The thread will execute in this function */
void *runner(void *param)
{
    int i, upper = atoi(param);   // Convert string argument to integer
    sum = 0;                      // Initialise the global sum

    for (i = 1; i <= upper; i++)
        sum += i;                 // Compute 1 + 2 + ... + upper

    pthread_exit(0);             
    // Terminates the thread cleanly
}