#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to append a string to a dynamically allocated buffer
void append_to_buffer(char** buffer, const char* text) {
    size_t current_length = (*buffer) ? strlen(*buffer) : 0;
    size_t additional_length = strlen(text);

    // Reallocate memory to accommodate the new text
    char* temp =(char *) realloc(*buffer, current_length + additional_length + 1);
    if (!temp) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(*buffer);
        exit(EXIT_FAILURE);
    }
    *buffer = temp;

    // Append the new text
    strcpy(*buffer + current_length, text);
}

char* c_strjoin(const char* str1, const char* str2) {

    char* buff = NULL; // Dynamic buffer initialized to NULL

    append_to_buffer(&buff, "str1: ");
    append_to_buffer(&buff, str1);
    append_to_buffer(&buff, "\nstr2: ");
    append_to_buffer(&buff, str2);
    append_to_buffer(&buff, "\n");

    // Simulate str1.append(str2)
    char* appended = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    if (!appended) {
        fprintf(stderr, "Memory allocation failed\n");
        free(buff);
        return NULL;
    }
    strcpy(appended, str1);
    strcat(appended, str2);

    append_to_buffer(&buff, ": 1-str1.append(str2) : \n");
    append_to_buffer(&buff, appended);
    append_to_buffer(&buff, "\n");

    // Simulate str1.assign(str2)
    append_to_buffer(&buff, ": str1.assign(str2); : \n");
    append_to_buffer(&buff, str2);
    append_to_buffer(&buff, "\n");

    append_to_buffer(&buff, "\n\n ------end-----\n\nstr1: ");
    append_to_buffer(&buff, str2); // Simulated str1 is now equal to str2
    append_to_buffer(&buff, "\n str2: ");
    append_to_buffer(&buff, str2);

    // Free temporary appended string
    free(appended);

    return buff;
}


// int main() {
//     const char* str1 = "Hello";
//     const char* str2 = " World";

//     char* result = strjoin(str1, str2);
//     if (result) {
//         printf("%s\n", result);
//         free(result); // Free allocated memory
//     }

//     return 0;
// }
