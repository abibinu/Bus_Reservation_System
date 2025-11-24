#include "header.h"

void print_banner(const char *title) {
    clrscr();
    printf("===============================================\n");
    printf("        %s\n", title);
    printf("===============================================\n\n");
}

void print_menu(const char *options[], int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s\n", options[i]);
    }
    printf("\n");
}

void pause_msg(const char *msg) {
    if (msg && msg[0] != '\0')
        printf("%s\n", msg);
    else
        printf("Press any key to continue...\n");
    getch();
}
