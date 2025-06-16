#include "kernel/types.h"
#include "kernel/riscv.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <number_of_tickets>\n", argv[0]);
        exit(1);
    }

    printf("Setting ticket for parent process\n");

    // Get the number of tickets from command-line argument
    int number = atoi(argv[1]);
    int r = settickets(number);

    // Check if ticket assignment is successful
    if (r < 0)
    {
        printf("settickets unsuccessful!\n");
    }
    else
    {
        printf("settickets successful!\n");
    }

    // Create a child process
    int val = fork();

    if (val == 0) 
    {
        // Child process code
        printf("\nFork successful (Child)\n");
        exit(0);  // Ensure child process terminates
    }
    else if (val < 0) 
    {
        // Fork failed
        printf("\nFork unsuccessful\n");
    }
    else
    {
        // Parent process code
        printf("\nFork successful (Parent)\n");
        wait(0);  // Wait for child to finish
    }

    return 0;
}
