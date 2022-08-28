#include<csapp.h>
#define MAXARGS 128

void eval(char *cmdline);
int parseline(char *buf,char **argv);
int builtin_command(char **argv);

void print_time(){
    time_t now;
    char timestr[128]="";
    time(&now);
    strftime(timestr, 128, "%a %d %b %Y %H:%M:%S GMT", localtime(&now));
    printf("Now is %s\n\n", timestr);
}

void sigint_handler(int sig){
    printf("\nGoodbye :P\n");
    exit(0);
}

int main(){
    char cmdline[MAXARGS];
    char ch;

    printf("Welcome to TinyShell! :D\n");
    print_time();

    if(signal(SIGINT,sigint_handler)==SIG_ERR)
        unix_error("signal error");
    if(signal(SIGTSTP,sigint_handler)==SIG_ERR)
        unix_error("signal error");

    while(1){
        printf("> ");

        Fgets(cmdline,MAXLINE,stdin);
        if(feof(stdin))
            exit(0);

        eval(cmdline);
    }
}

void eval(char *cmdline){
    char *argv[MAXARGS];
    char buf[MAXARGS];
    int bg; // if runs in background
    pid_t pid;

    strcpy(buf,cmdline);
    bg=parseline(buf,argv);
    if(argv[0]==NULL) return;

    if(!builtin_command(argv)){
        if((pid=Fork())==0){
            if(execve(argv[0],argv,environ)){
                printf("%s: Command not found.\n",argv[0]);
            }
        }
        if (!bg){
            int status;
            if(waitpid(pid,&status,0)<0)
                unix_error("waitfg: waitpid error");
        } else {
            printf("%d %s",pid,cmdline);
        }
    }

        return;
}

int builtin_command(char **argv){
    if(!strcmp(argv[0],"quit"))
        exit(0);
    if(!strcmp(argv[0],"&"))
        return 1;
    if(!strcmp(argv[0],"\n"))
        return 1;
    return 0;
}

int parseline(char *buf,char **argv){
    char *delim;    // points to first space delimiter
    int argc=0;
    int bg; // if runs in background

    if(buf[0]=='\n') {
        argv[0]=NULL;
        return -1;
    }
    buf[strlen(buf)-1]=' ';
    while(*buf&&(*buf==' '))
        buf++;

    argc=0;
    while((delim=strchr(buf,' '))){
        argv[argc++]=buf;
        *delim='\0';
        buf=delim+1;
        while(*buf && (*buf)==' ')
            buf++;
    }
    argv[argc]=NULL;

    if((bg=(*argv[argc-1]=='&'))!=0)
        argv[--argc]=NULL;

    return bg;
}