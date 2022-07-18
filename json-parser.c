/*
*   Today:          18th July 2022
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <json-c/json.h>


int main (int argc, char *argv[]) 
{
    if (argc != 3) {
        printf("%s requires 2 arguments. You supplied %d\n", argv[0], argc-1);
        exit(1);
    }

    // Check file exists and can be read
    if (access(argv[1], F_OK | R_OK) == -1) {
        perror(NULL);
        exit(1);
    }

    json_object *haystack = json_object_from_file(argv[1]);
    if (haystack == NULL) {
        printf("Invalid JSON\n");
        exit(1);
    }

    // Placeholder object for what we're searching for
    json_object *needle = NULL;

    if (json_object_object_get_ex(haystack, argv[2], &needle)) {
        printf("%s\n", json_object_get_string(needle));
        exit(0);
    }

    json_object_put(haystack);
    return 0;
 

}