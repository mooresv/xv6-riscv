#include "kernel/param.h" 
#include "kernel/types.h" 
#include "kernel/stat.h" 
#include "kernel/pstat.h" 
#include "user/user.h" 
#define MAXARGS 16

int
main(int argc, char *argv[]){
	int i;
	int start;
  int elapsed; 
	int rc;
	char *newargv[MAXARGS];
	struct rusage ru;

	if(argc < 2){
		printf ("Usage: time <comm> [args...]");
		exit(-1);
	}
	for(i=1; i<argc; i++){
		newargv[i-1] = argv[i];
    }    
	newargv[argc-1] = 0;
	start = uptime ();
	rc = fork();
	if (rc == 0){
		exec (newargv[0], newargv);
    }    
	wait2(0, &ru); // parent
	elapsed = uptime() - start;
	printf("elapsed time: %d ticks, cpu time: %d ticks, %d% CPU\n", elapsed, ru.cputime, ru.cputime*100/elapsed);

    exit(0);
}