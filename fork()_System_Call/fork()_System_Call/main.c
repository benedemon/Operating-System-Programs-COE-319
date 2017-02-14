//
//  main.c
//  fork()_System_Call
//
//  Created by Raj Singh on 14/02/17.
//  Copyright © 2017 benedemon. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char **argv)
{
    pid_t pid;
    pid = fork();
    if(pid==0)
    {
        printf("It is the child process with pid %d\n",getpid());
        exit(0);
    }
    else if(pid > 0)
    {
        printf("It is the parent process with pid %d\n",getpid());
    }
    else
    {
        printf("Error in forking..\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
