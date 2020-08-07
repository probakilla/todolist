#include <stdio.h>
#include <stdlib.h>

#include "user.h"

int main() {
    char* input = ask_user("Hello, please enter something\n");
    printf(input);
    free(input);
    return EXIT_SUCCESS;
}
