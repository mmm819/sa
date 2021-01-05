/******************************************************************
 *Copyright(c) 2020 Ocean University of China.All rights resigned.*
 *This file is created by:                                        *
 *          #       #                                             *
 *         # #     # #                                            *
 *        #   #   #   #                                           *
 *       #     # #     #                                          *
 *      #       #       #                                         *
 ******************************************************************/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(void)
{
	int pid1,pid2;
	lockf(1,1,0);      //对父进程进行加锁
	printf("Parent process:a\n");
	if((pid1=fork())<0)
	{
		printf("child1 fail create\n");
		return 1;
	}
	else if(pid1==0)
	{
		lockf(1,1,0);  //对子进程进行加锁
		printf("This is child1(pid=%d) process:b\n",getpid());
		lockf(1,0,0);   //解锁
		return 0;
	}
	if((pid2=fork())<0)
	{
		printf("child2 fail create\n");
		return 1;
	}
	else if(pid2==0)
	{
		lockf(1,1,0);
		printf("This is child2(pid=%d) process:c\n",getpid());
		lockf(1,0,0);
		return 0;
	}
	lockf(1,0,0);
       return 0;}
