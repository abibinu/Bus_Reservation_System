#include "header.h"

int main() {
    int choice;

    while (1) {
        const char *menu[] = {
            "1. Manage - Add Records",
            "2. Manage - Remove Records",
            "3. Manage - Update Records",
            "4. Display Records",
            "5. Exit"
        };

        print_banner("BUS RESERVATION SYSTEM");
        print_menu(menu, sizeof(menu) / sizeof(menu[0]));

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {};
            printf("Invalid input. Please enter a number.\n");
            pause_msg(NULL);
            continue;
        }

        switch(choice) {
            case 1: insertionMenu(); break;
            case 2: deletionMenu(); break;
            case 3: updationMenu(); break;
            case 4: viewMenu(); break;
            case 5: exit(0);
            default:
                printf("\nInvalid choice!\n");
                pause_msg(NULL);
        }
    }
    return 0;
}
