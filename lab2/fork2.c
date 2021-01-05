/******************************************************************
 *Copyright(c) 2020 Ocean University of China.All rights resigned.*
 *This file is created by:                                        *
 *          #       #                                             *
 *         # #     # #                                            *
 *        #   #   #   #                                           *
 *       #     # #     #                                          *
 *      #       #       #                                         *
 ******************************************************************/
# include<stdio.h>
# include<sys/types.h>
# include<unistd.h>
int main()
{
	int pid1,pid2;
	printf("I am father!\n");
	if((pid1=fork())<0)
	{
		printf("Child fail create!\n");
		return 1;

	}
	else if(pid1==0)
	{
		if((pid2=fork())<0)
		{
			printf("c fail create!\n");
			return 1;
		}
		else if (pid2==0)
		{
			printf("c\n");
			return 0;
		}
		else
		{
			printf("I am son!\n");
			return 0;
		}
	}
}
