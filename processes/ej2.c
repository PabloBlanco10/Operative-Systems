#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char ** argv){
	//system(argv[1]);

	pid_t p = fork();

	if(p == 0){
		setsid();
		int fd1 = open("entrada.txt", O_CREAT | O_RDWR);
		int fd2 = open("salida.txt", O_CREAT | O_RDWR);
		int fd3 = open("error.txt", O_CREAT | O_RDWR);
		dup2(fd1, 0);
		dup2(fd2, 1);
		dup2(fd3, 2);
		execvp(argv[1], argv+1);
		//execlp(argv[1], argv[1], argv[2], NULL);
	}
	else{
		sleep(1);
		printf("El comando termino \n");
	}
	return 0;
}
