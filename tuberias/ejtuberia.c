#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <fcntl.h>
#include <string.h>
#include <sys/select.h>

int main(int argc, char ** argv){

    mkfifo("tuberia");
	int fd = open("tuberia", O_WRONLY);
	char buffer[256];
	strcpy(buffer, argv[1]);
	buffer[strlen(argv[1])] = '\n';
	if(fd != -1){
		write(fd, buffer, strlen(argv[1])+1);
		printf(" EXITO \n");
	}
	else{
		printf(" ERROR \n");
	}

return 0;
}
