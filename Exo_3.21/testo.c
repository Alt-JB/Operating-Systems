#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 

int main()
{
int num,check,a; 
char term; 
check = 0;

while (check != 1)
{
    check = 0;

   label: a= scanf("%d%c", &num, &term);
    if( a != 2 || term != '\n') 
    {//check = 0;
        goto label;
        printf("failure\n"); 
        
    }
    else 
    {
         
        
        if (num > 0)
        {
            check = 1;
            printf("valid integer followed by enter key\n");
        }
        else 
            check = 0;
    }
    
}


}