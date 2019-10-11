#include<sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	char *p[0];
	int pid=fork();
	int status;
	if(pid==0){
		char* const a[] = {"ls", "/home",NULL};
		printf("%u\n", getpid());
		printf("This is child, sleeping for 2 sec\n");
		execv("ls", a);
		sleep(2);
		exit(0);
	} else {
		wait(&pid);
		printf("%u\n", getpid());

		printf("This is parent, child has exited\n");
	}
	// else{
	// 	wait(pid);
	// }
	return 0;
}