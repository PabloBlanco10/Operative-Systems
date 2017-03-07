#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

static volatile int borrado = 0;

void handler(int signal){
		if(signal == SIGUSR1)
			borrado=1;
}

int main(int argc, char ** argv){

	struct sigaction act;
	act.sa_handler = handler;
	act.sa_flags = SA_RESTART;
	printf("%i \n",getpid());
	
	sigaction(SIGALRM, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	alarm(atoi(argv[1]));
	pause();
	
	if(borrado == 0){
		printf("ELIMINAR \n");
		system("rm sen");
	}
	else{
		printf("DETENER \n");
	}
	
return 0;
}
