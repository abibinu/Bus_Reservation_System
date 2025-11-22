#include "header.h"

void viewMenu() {
    int ch;

    while (1) {
        clrscr();
        printf("\n---------- VIEW MENU ----------");
        printf("\n1. View Buses");
        printf("\n2. View Passengers");
        printf("\n3. View Reservations");
        printf("\n4. Back");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: viewBus(); break;
            case 2: viewPassenger(); break;
            case 3: viewReservation(); break;
            case 4: return;
            default:
                printf("\nInvalid choice!");
                getch();
        }
    }
}
