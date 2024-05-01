#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{

	
	pid_t childpid=fork();
	if(childpid==-1)
	{
		printf("child execution unsuccessful\n");
		
	}
	else if(childpid==0){
		printf("child process\n");
		printf("pid %d \n",getpid());
		printf("Parent pid %d \n",getppid());
		
		
	}
	else{
		printf("parent process \n");
		printf("PID %d\n",getpid());
		printf("child PID %d\n",childpid);
		wait(NULL);
		printf("child finished");
		exit(0);
	}
	return 0;
	
	
}
