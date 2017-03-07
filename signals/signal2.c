#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

static volatile int conti = 0;
static volatile int conts = 0;

void handler(int signal){
	if(signal == SIGINT)
		conti++;
	if(signal == SIGTSTP)
                conts++;
}

int main() {

	struct sigaction act;
	act.sa_handler = handler;
	act.sa_flags = SA_RESTART;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGTSTP, &act, NULL);

	while(conti + conts < 10);

	printf( "\n NUM VECES DE SIGINT = %i \n", conti);
	printf( " NUM VECES DE SIGTSTP = %i \n", conts);

	return 0;
}
