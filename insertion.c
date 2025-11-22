#include "header.h"

void insertionMenu() {
    int ch;

    while (1) {
        clrscr();
        printf("\n---------- INSERTION MENU ----------");
        printf("\n1. Insert Bus");
        printf("\n2. Insert Passenger");
        printf("\n3. Insert Reservation");
        printf("\n4. Back");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insertBus(); break;
            case 2: insertPassenger(); break;
            case 3: insertReservation(); break;
            case 4: return;
            default:
                printf("\nInvalid choice!");
                getch();
        }
    }
}
