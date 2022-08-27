#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void unix_error(char *msg){
    fprintf(stderr,"error: %s\n",msg);
    exit(0);
}

pid_t Fork(){
    pid_t pid;
    if((pid=fork())<0)
        unix_error("Fork error");
    return pid;
}

int main(){
    Fork();
    Fork();
    printf("hello\n");
    exit(0);
}