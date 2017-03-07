
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char ** argv){
	
	int p_h[2];
	int h_p[2];
	
	pipe(p_h);
	pipe(h_p);
	
	pid_t pid = fork();
	char buffer [256];
	char received;
	
	if(pid == -1)
		perror("ERROR \n");
		
	else if(pid == 0) {
		//HIJO
		
		close(p_h[1]);
		close(h_p[0]);
		received = 'l';
		int i;
		for(i = 0; i < 10; i++){
			
			int bytes = read(p_h[0], buffer, 256);
			buffer[bytes] = '\0';
			printf("Soy hijo, mensaje leido: \n");
			write(1, buffer, bytes);
			sleep(1);
			if(i == 9)
				received = 'q';
				
			write(h_p[1], &received, 1);
		}
		exit(0);
	}
	else{
		//PADRE
		close(p_h[0]);
		close(h_p[1]);
		
		while(received != 'q'){
			printf("Soy padre, nuevo mensaje: \n");
			int bytes = read(0, buffer, 256);
			buffer[bytes] = '\0';
			write(p_h[1], buffer, bytes);
			read(h_p[0], &received, 1);
		}
		
	}
	wait(NULL);
	return 0;
}
