#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  struct pstat procp[NPROC];
  int nprocs;

  nprocs = getprocs(procp);
  if (nprocs < 0)
    exit(-1);

  // You can remove the following print statement
  printf("%d processes\n", nprocs);

  /*********************************
   * Add your code here to output information returned by getprocs()
   * Hint: see procdump() code in kernel/console.c, except that here
   * you will be outputting the first nprocs elements of the uproc array
   * and all will have active states.
   *********************************/ 
  static char *states[] = {
  [UNUSED]    "unused",
  [SLEEPING]  "sleep ",
  [RUNNABLE]  "runble",
  [RUNNING]   "run   ",
  [ZOMBIE]    "zombie"
  };
  //struct proc *p;
  struct pstat *p;
  char *state;

  printf("\n");
  printf("pid  state  name  cpu_time size \n");
  // get value that returns from getprocs 
  for(p = procp; p < &procp[NPROC]; p++){
    if(p->state == UNUSED)
      continue;
    if(p->state >= 0 && p->state < ((sizeof(states)/sizeof((states)[0]))) && states[p->state])
      state = states[p->state];
    else
      state = "???";

    printf("%d   %s   %s    %d   %d", p->pid, state, p->name, p->cpu_time, p->size);
    printf("\n");
  }




  exit(0);
}
