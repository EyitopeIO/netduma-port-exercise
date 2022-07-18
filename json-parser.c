/*
*   Today:          18th July 2022
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <json-c/json.h>

void iterate_deeper_into_jsontree(json_object *arraytree, char * key_elem);


int main (int argc, char *argv[]) 
{
    if (argc != 3) {
        printf("%s requires 2 arguments. You supplied %d\n", argv[0], argc-1);
        exit(EXIT_FAILURE);
    }

    // Check file exists and can be read
    if (access(argv[1], F_OK | R_OK) == -1) {
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    json_object *haystack = json_object_from_file(argv[1]);
    if (haystack == NULL) {
        printf("Invalid JSON\n");
        exit(EXIT_FAILURE);
    }

    // Placeholder object for what we're searching for
    json_object *needle = NULL;

    if (json_object_object_get_ex(haystack, argv[2], &needle)) {
        printf("%s\n", json_object_get_string(needle));
        exit(EXIT_SUCCESS);
    }
    else {
        iterate_deeper_into_jsontree(haystack, argv[2]);
    }

    json_object_put(haystack);

    printf("\"\"\n");

    return 0;
 

}


void iterate_deeper_into_jsontree(json_object *treetop, char *key_elem)
{
    json_object *needle = NULL;

    json_object_object_foreach(treetop, key, tmp) {

        switch (json_object_get_type(tmp)) {

            case json_type_object:
                iterate_deeper_into_jsontree(tmp, key_elem);
                break;
            
            case json_type_array:
                break;
            
            default:
                if (json_object_object_get_ex(treetop, key_elem, &needle)) {
                    printf("%s\n", json_object_get_string(needle));
                    return;
                }
        }
    }
}