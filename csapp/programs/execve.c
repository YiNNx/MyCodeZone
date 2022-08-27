#include<unistd.h>

int main(){
    char argv[3][3];
    execve("./hello",argv,argv);
    return 0;
}