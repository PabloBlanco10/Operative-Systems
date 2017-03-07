#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	

	sigset_t set;
	sigemptyset(&set);
	sigset_t pending;
	sigemptyset(&pending);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGTSTP);
	sigprocmask(SIG_BLOCK, &set, NULL);
	sleep(10);
	
	
	if(sigpending(&pending) != -1){
		printf("\n PULSANDO \n");
		if(sigismember(&pending, SIGINT)){
			printf(" SIGINT PULSADO \n");
		}
		if(sigismember(&pending, SIGTSTP)){
			printf(" SIGSTP PULSADO \n");
			sigprocmask(SIG_UNBLOCK, &set, NULL);
		}
	}
	else{
		printf("\n UNABLE TO READ PENDINGS \n");
		return -1;
	}
return 0;
}












