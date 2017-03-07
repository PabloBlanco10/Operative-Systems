#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

//static volatile int alarma = 0;

void handler(int signal){
	printf("Ejecutando tarea programada \n");
}

int main(int argc, char ** argv){
	
	int sec = atoi(argv[1]);

	pid_t pid = fork();
	
	struct sigaction act;
	act.sa_handler = handler;
	act.sa_flags = SA_RESTART;
	
	if(pid == -1){
		perror("ERROR \n");
		return -1;
	}
	else if(pid == 0){ 
		//hijo
		sigaction(SIGALRM, &act, NULL);
		alarm(sec);
		pause();
		//int fd = creat("/tmp/examen.out", 0666);
		int fd = open("/tmp/examen.out", O_CREAT | O_RDWR);
		chmod("/tmp/examen.out", 0666);
		dup2(fd, 1);
		//execlp(argv[2],argv[2],argv[3],NULL);
		execvp(argv[2], argv+2);
	}else{
		//padre
		printf("Ejecución programada en %i segundos por proceso %i \n", sec, pid);
		wait(NULL);
	}
	return 0;
}
