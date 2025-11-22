#include "header.h"

void main() {
    int choice;

    while (1) {
        clrscr();
        printf("\n==========================================");
        printf("\n        BUS RESERVATION SYSTEM");
        printf("\n==========================================");
        printf("\n1. Insert Records");
        printf("\n2. Delete Records");
        printf("\n3. Update Records");
        printf("\n4. View Records");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertionMenu(); break;
            case 2: deletionMenu(); break;
            case 3: updationMenu(); break;
            case 4: viewMenu(); break;
            case 5: exit(0);
            default:
                printf("\nInvalid choice!");
                getch();
        }
    }
}
