#include <conio.h>
#include <process.h>
#include <sched.h>
#include <sema.h>
#include <string.h>

#if !defined (NULL)
#define NULL 0
#endif

int main(int argc, char **argv) {
    int policy = -1;
    int holdsched3_sem;

    int id1, id2, id3;          /* ID of child process */
    holdsched3_sem = Open_Semaphore("holdsched3_sem", 0);

    if (argc >= 2) {
        if (!strcmp(argv[1], "rr")) {
            policy = 0;
        } else if (!strcmp(argv[1], "mys")) {
            policy = 1;
        } else {
            Print("usage: %s [rr|mys]\n", argv[0]);
            Exit(1);
        }
        Set_Scheduling_Policy(policy, 10);      /* second parameter may be unused. */
    } else {
        Print("usage: %s [rr|mys]\n", argv[0]);
        Exit(1);
    }

    id3 = Spawn_Program("/c/sched3.exe", "/c/sched3.exe", 0);
    id1 = Spawn_Program("/c/sched1.exe", "/c/sched1.exe", 0);
    id2 = Spawn_Program("/c/sched2.exe", "/c/sched2.exe", 0);


    Wait(id1);
    Wait(id2);
    Wait(id3);

    Print("\n");

    Close_Semaphore(holdsched3_sem);

    return 0;
}
