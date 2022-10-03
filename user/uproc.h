enum uprocstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

struct uproc {

int pid; // Process ID

enum uprocstate state; // Process state

uint64 size; // Size of process memory (bytes)

int ppid; // Parent ID

char name[16]; // Process command name

int cpu_time;
};