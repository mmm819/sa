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
	int pid,pid2;
        printf("I am father!    process id:%d\n",getpid());
        if ((pid = fork())<0) //create son
	{ printf("son fail create!\n");
          return 1;
        }
        else if (pid == 0)
        {
	   printf("I am son!    process id:%d\n",getpid());
           return 0 ;
        }
        if ((pid2 = fork())<0) //create daughter
        { printf("daughter fail create!\n");
          return 1;
        }
        else if (pid2 == 0)
        { printf("I am daughter!    process id:%d\n",getpid());
          return 0 ;
        }
	return 0;
}
