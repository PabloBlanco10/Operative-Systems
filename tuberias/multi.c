#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <fcntl.h>
#include <string.h>
#include <sys/select.h>

#define MAX_BUF 256

int main(int argc, char ** argv){

	int fd1 = open("tuberia", O_RDONLY);
	int fd2 = open("tuberia2", O_RDONLY);
	
	int rc;
	
	char buf[MAX_BUF];
	fd_set set;
	
	do{
		FD_ZERO(&set);
		FD_SET(fd1 ,&set);
		FD_SET(fd2 ,&set);
		rc = select(fd2+1, &set, NULL,NULL,NULL);
	}while(rc == -1);
	
	int bytes;
	if(FD_ISSET(fd1, &set)){
		printf("Tuberia 1 \n");
		 bytes = read(fd1,buf,256);
	}else if (FD_ISSET(fd2, &set)){
		printf("Tuberia 2 \n");
		bytes = read(fd2,buf,256);
	}
	printf(buf);
	printf("\n");
	
	

return 0;
}


