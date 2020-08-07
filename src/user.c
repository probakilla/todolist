#include <stdio.h>
#include <malloc.h>

#define INPUT_MAX_LENGTH 64

char* ask_user(char* message) {
    char* input = (char*) malloc(INPUT_MAX_LENGTH * sizeof(char));
    printf(message);
    fgets(input, INPUT_MAX_LENGTH, stdin);
    return input;
}
