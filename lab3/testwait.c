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
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
  pid_t pid;
  int status,i;
  if(fork()==0){          //子进程
    printf("This is the child process .pid =%d\n",getpid()); //得到子进程识别码
    exit(5);      //子进程退出
  }
  else{                   //父进程
    sleep(1);
    printf("This is the parent process ,wait for child...\n");
    pid=wait(&status);
    //取得子进程exit返回的结束代码
    i=WEXITSTATUS(status);
    printf("child’s pid =%d .exit status=%d\n",pid,i);
  }
}

