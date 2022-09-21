#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
  
int main(int argc , char *argv[] )
{
    pid_t pid;
  
    if (argc != 2)
    {
        printf("arg missing or exceeding\n");
        exit(0);
    }
  
    // atoi converts string to integer
    if ( atoi ( argv[1] ) <0 )
    {
        printf("negative number entered %d", atoi(argv[1]));
        exit(0);
    }
  
    pid=fork();
  
    if ( pid<0 )
    {
        printf("failed to create child\n");
        exit(0);
    }
  
    else if ( pid==0 )
    {
        //Child Process
        int ans = 0, i, j, k = 2, n;
  
        // atoi converts string to integer
        n = atoi(argv[1]);
        int arr[n],sum[n];
  
        arr[0] = 1;
  
        // generating factorial series
        for (i=1 ; i<n; i++)
        {
            arr[i] = arr[i-1]*k;
            k++;
        }
  
        // printing and sum of each sub-series
        for (j=0; j<n; j++)
        {
            sum[j] = 0;
            for (i=0; i<=j; i++)
            {
                printf(" %d ",arr[i]);
                sum[j]+=arr[i];
            }
            printf("\n");
        }
    }
  
    // parent process
    else
    {
        wait(NULL);
  
        // waiting for child process to end
        printf("Done\n");
    }
}