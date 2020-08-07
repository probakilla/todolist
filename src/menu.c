#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int input_line = 4;

#define gotostart() printf("\033[%d;%dH", input_line, 0)
#define clear_current() printf("%c[2K", 27)
#define MAX_INPUT_LEN 64

static void ghost_keypress() {
	clear_current();
	gotostart();
}

static char* ask_filename() {
    system("/bin/stty cooked");
	system("clear");
	printf("Please enter a file name\n");
	char* input = (char*) malloc(MAX_INPUT_LEN * sizeof(char));
	fgets(input, MAX_INPUT_LEN, stdin);
	return input;
}

static void user_keypress() {
    int c;
    system("/bin/stty raw");
    while((c = getchar()) != 'q') {
		ghost_keypress();
		switch (c) {
			case 'a':
			char* filename = ask_filename();
			break;
		}
    }
	ghost_keypress();
}

void file_menu() {
    system("clear");
    printf("Hello ! What do you want to do ?\n");
    printf("a) add list\n");
    printf("q) quit\n");
    user_keypress();
}

