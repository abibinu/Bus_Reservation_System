#include "header.h"

void insertBus() {
    struct Bus b;
    FILE *fp;
    int idFound = 0;
    struct Bus temp;

    clrscr();
    printf("\n=========== INSERT NEW BUS ===========");

    printf("\nEnter Bus ID: ");
    scanf("%d", &b.b_id);

    // --- Check if Bus ID already exists ---
    fp = fopen("bus.dat", "rb");
    if (fp != NULL) {
        while (fread(&temp, sizeof(temp), 1, fp)) {
            if (temp.b_id == b.b_id) {
                idFound = 1;
                break;
            }
        }
        fclose(fp);
    }

    if (idFound) {
        printf("\nBus ID already exists! Try another ID.");
        getch();
        return;
    }

    // --- Input remaining details ---
    printf("Enter Bus Name: ");
    scanf("%s", b.b_name);

    printf("From (Source): ");
    scanf("%s", b.b_from);

    printf("To (Destination): ");
    scanf("%s", b.b_to);

    printf("Number of Seats: ");
    scanf("%d", &b.b_seats);

    printf("Fare: ");
    scanf("%d", &b.b_fare);

    // --- Insert into file ---
    fp = fopen("bus.dat", "ab");
    if (fp == NULL) {
        printf("\nError opening file!");
        getch();
        return;
    }

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("\nBus Added Successfully!");
    getch();
}


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
