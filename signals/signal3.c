#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

static volatile int borrado = 0;

void handler(int signal){
	if(signal == SIGUSR1)
		borrado = 1;
}

int main(int argc, char ** argv){

	struct sigaction act;
	act.sa_handler = handler;
	act.sa_flags = SA_RESTART;
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	if(sigaction(SIGUSR1, &act, NULL) == -1){
		printf("ERROR \n");
		return -1;
	}

	sleep(atoi(argv[1]));
	if(borrado != 1){
		printf("ARCHIVO BORRADO \n");
		system("rm signal3");
	}	

return 0;
}
