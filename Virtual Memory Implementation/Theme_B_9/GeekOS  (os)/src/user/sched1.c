#include <conio.h>
#include <process.h>
#include <sched.h>
#include <sema.h>
#include <string.h>

int main(int argc __attribute__ ((unused)), char **argv
         __attribute__ ((unused))) {

    int i, j;                   /* loop index */
    int holdsched3_sem;

    holdsched3_sem = Open_Semaphore("holdsched3_sem", 0);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 20000; j++);
        Print("1");
    }

    V(holdsched3_sem);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 20000; j++);
        Print("1");
    }

    Close_Semaphore(holdsched3_sem);

    return 0;
}