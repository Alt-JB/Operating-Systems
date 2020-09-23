#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 

int even (int n)
{
    n= n / 2;
    if (n == 1)
        printf("1.");
    else     
        printf("%d,",n);
    return n;
}

int odd (int n )
{
    n = 3*n + 1;
    if (n == 1)
        printf("1.");
    else     
        printf("%d,",n);
    return n;
}

int  Collatz_conjecture (int n)
{
    int number = 0;
    number = n;

    if (number == 1)
        {
            printf("1.");
            return 0;
        }
    
    while (number > 1)
    {
         if (number%2 == 0)
        {
            number = even(number);
        }
        else if (number%2 == 1)
        {
            number = odd (number);
        }
    }
    return 1;
}

int main ()
{
    int input;//temporary
    pid_t pid ; //to identify the child process

    printf("                Collatz conjecture algorithm\n");
    do
    {
        printf("Enter a positive integer : ");
        //scanf("%d",&input); //apply fonction to validate user's input
        if (scanf("%d", &input) != 1)
        {
            printf("This is not a number.\n");
            return 0;
            //input=0;
            //goto bar;
        }
    }
    while (input<=0);// || scanf("%d", &input) != 1);

    pid = fork();  //creates the child process

         if (pid == -1) //check if the process was actually created
         {
             perror("Error creating child");
             return -1;
         }
         else if (pid == 0) //Child created succesfully
         {
             printf("Child was succefully created with ID : %d \n",getpid());
             printf("%d,",input);
             Collatz_conjecture(input);             
             printf("\nChild has finished");
            
         }
         else
         {
             wait(NULL); // makes the parent process wait until the child process is done .
            printf("\nParent is executing with ID: %d\n",getpid());
         }
         
    return 0;

}
