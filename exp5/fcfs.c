#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
	{
	 int pno,avgwt=0,avgtt=0;
	 int wt=0,tt=0;
	 
	 printf("Enter the number of process : ");
	 scanf("%d",&pno);
	 int wtime[pno];
	 int btime[pno];
	 int turntime[pno];
	 
	 for(int i=1;i<=pno;i++)
	 	{
		   printf("Enter the burst time of P%d : ",i);
		   scanf("%d",&btime[i]);	 	
	 	}
	 	
	 wtime[1]=0;
	 for(int i=2;i<=pno;i++)
	 	{
	 	 wtime[i]=wtime[i-1]+btime[i-1];
	 	 wt=wt+wtime[i];
	 	 
	 	}
	 avgwt=wt/pno;
	 for(int i=1;i<=pno;i++)
	 	{
	 	turntime[i]=btime[i-1]+wtime[i-1];
	 	tt=tt+turntime[i];
	 	}
	 avgtt=tt/pno;
	printf("Average waiting time is: %dms\n",avgwt);
	printf("Average Turn Around Time time is: %dms\n",avgtt);
	
	printf("process ID    BurstT        WaitingT          TAT");
	   for(int i=1;i<=pno;i++)
	   {
	      printf("\n p[%d]  \t\t  %d \t\t %d  \t\t %d",i,btime[i],wtime[i],turntime[i]);
	   }
	   printf("\nGantt chart");
	   int temp=0;
	   printf("\n========================\n");
	   for(int i=0;i<=pno;i++)
	   printf(" p%d ",i+1);
	   printf("\n========================\n");
	   for(int i=0;i<=pno;i++)
	   {
	     printf("%d  ",temp);
	     temp=temp+btime[i];
	   }
	
	}
