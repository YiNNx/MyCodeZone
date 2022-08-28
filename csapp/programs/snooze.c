#include<csapp.h>

void sigint_handler(int sig){
    return;
}

void snooze(int secs){
    unsigned int rc=sleep(secs);
    printf("slept for %d of %d seconds\n",secs-rc,secs);
}

int main(int argc, char **argv){
    if (argc!=2) {
        unix_error("no arguements");
        return 0;
    }

    // start_time = clock();
    if(signal(SIGINT,sigint_handler)==SIG_ERR)
        unix_error("signal error");

    snooze(atoi(argv[1]));
    return 0;
}