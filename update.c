#include "header.h"

void updationMenu() {
    int ch;

    while (1) {
        clrscr();
        printf("\n---------- UPDATION MENU ----------");
        printf("\n1. Update Bus");
        printf("\n2. Update Passenger");
        printf("\n3. Update Reservation");
        printf("\n4. Back");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: updateBus(); break;
            case 2: updatePassenger(); break;
            case 3: updateReservation(); break;
            case 4: return;
            default:
                printf("\nInvalid choice!");
                getch();
        }
    }
}
