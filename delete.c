#include "header.h"

void deletionMenu() {
    int ch;

    while (1) {
        clrscr();
        printf("\n---------- DELETION MENU ----------");
        printf("\n1. Delete Bus");
        printf("\n2. Delete Passenger");
        printf("\n3. Delete Reservation");
        printf("\n4. Back");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: deleteBus(); break;
            case 2: deletePassenger(); break;
            case 3: deleteReservation(); break;
            case 4: return;
            default:
                printf("\nInvalid choice!");
                getch();
        }
    }
}
