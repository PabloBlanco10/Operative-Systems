#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <fcntl.h>
#include <string.h>
#include <sys/select.h>

int main(){

	int fd = open("tuberia", O_WRONLY);
	char buffer[256];
	scanf("%s", buffer);
	buffer[strlen(buffer)+1] = '\n';
	if(fd != -1){
		write(fd, buffer, strlen(buffer)+1);
		printf(" EXITO \n");
	}
	else{
		printf(" ERROR \n");
	}

return 0;
}
