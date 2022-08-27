#include<unistd.h>

int main(){
    write(1,"hello world\n",5);
    _exit(-1);
}