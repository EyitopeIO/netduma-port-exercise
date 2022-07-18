/*
*   Today:          18th July 2022
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char *argv[]) 
{
    if (argc != 3) {
        printf("%s requires 2 arguments. You supplied %d\n", argv[0], argc-1);
        exit(1);
    }

    // Check file exists and can be read
    if (access(argv[1], F_OK | R_OK) == -1) {
        perror(NULL);
    }

}