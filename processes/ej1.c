#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
/* Comprobar la ocurrencia de error y notificarlo con la llamada adecuada */


	//int i = 0;
	//for(; i < 255; i++){
		//printf("código %s \n", strerror(i));
	//}
	//system("uname -a");
	//printf("%d \n", sysconf(_SC_ARG_MAX));
	//printf("%d \n", pathconf("/Escritorio/p", _PC_PATH_MAX));
	//system("id -r -u usuarioso");
	//system("date"); 
	//const time_t *now = time(0);
	//char *c = ctime(now);
	
	
	//mode_t k = umask(277);
	//open("b", O_CREAT, S_IRWXU);

	//umask(0000);
	//struct stat buf; 
	//stat("a.txt", &buf);
	//printf("%i \n",buf.st_ino);
	//printf("%i \n", buf.st_dev);
	//printf("%i \n", buf.st_rdev);
	//printf("%i \n", buf.st_atime);
	//char name[20];
	//gets(name);
	//link(name, "f");
	//symlink(name, "g");
	
	//printf("%i \n", getpid());
	//printf("%i \n", getppid());
	//printf("%i \n", getgid());
	//printf("%i \n", getsid(getpid()));



	pid_t p = fork();

	if(p == 0){
		setsid();
		printf("%i \n", getpid());
		printf("%i \n", getppid());
		printf("%i \n", getgid());
		printf("%i \n", getsid(getpid()));
	}
	else{
		sleep(1);
		printf("padre = %i \n", getpid());
		printf("Padre %i \n", getsid(getpid()));

	}
	
	
	

	
	return 1;
}
