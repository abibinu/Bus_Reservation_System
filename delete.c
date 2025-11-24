#include "header.h"

void deleteBus() {
    FILE *fp, *ft;
    struct Bus b;
    int id, found = 0;
    print_banner("DELETE BUS");

    printf("Enter Bus ID to delete: ");
    scanf("%d", &id);

    fp = fopen("bus.dat", "rb");
    if (fp == NULL) {
        printf("\nNo bus data available to delete!");
        pause_msg(NULL);
        return;
    }

    ft = fopen("temp.dat", "wb");

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.b_id == id) {
            found = 1;   // skip this record (deleting)
        } else {
            fwrite(&b, sizeof(b), 1, ft); // save others
        }
    }

    fclose(fp);
    fclose(ft);

    remove("bus.dat");
    rename("temp.dat", "bus.dat");

    if (found)
        printf("\nBus deleted successfully!\n");
    else
        printf("\nBus ID not found!\n");

    pause_msg(NULL);
}

void deletePassenger() {
    FILE *fp, *ft;
    struct Passenger p;
    int id, found = 0;
    print_banner("DELETE PASSENGER");

    printf("Enter Passenger ID to delete: ");
    scanf("%d", &id);

    fp = fopen("passenger.dat", "rb");
    if (fp == NULL) {
        printf("\nNo passenger data available to delete!");
        pause_msg(NULL);
        return;
    }

    ft = fopen("temp.dat", "wb");

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.p_id == id)
            found = 1;
        else
            fwrite(&p, sizeof(p), 1, ft);
    }

    fclose(fp);
    fclose(ft);

    remove("passenger.dat");
    rename("temp.dat", "passenger.dat");

    if (found)
        printf("\nPassenger deleted successfully!\n");
    else
        printf("\nPassenger ID not found!\n");

    pause_msg(NULL);
}

void deleteReservation() {
    FILE *fp, *ft;
    struct Reservation r;
    int id, found = 0;
    print_banner("DELETE RESERVATION");

    printf("Enter Reservation ID to delete: ");
    scanf("%d", &id);

    fp = fopen("reservation.dat", "rb");
    if (fp == NULL) {
        printf("\nNo reservations available to delete!");
        pause_msg(NULL);
        return;
    }

    ft = fopen("temp.dat", "wb");

    while (fread(&r, sizeof(r), 1, fp)) {
        if (r.r_id == id)
            found = 1;
        else
            fwrite(&r, sizeof(r), 1, ft);
    }

    fclose(fp);
    fclose(ft);

    remove("reservation.dat");
    rename("temp.dat", "reservation.dat");

    if (found)
        printf("\nReservation deleted successfully!\n");
    else
        printf("\nReservation ID not found!\n");

    pause_msg(NULL);
}

void deletionMenu() {
    int ch;

    while (1) {
        const char *menu[] = {
            "1. Remove Bus",
            "2. Remove Passenger",
            "3. Cancel Reservation",
            "4. Back"
        };

        print_banner("REMOVAL MENU");
        print_menu(menu, sizeof(menu) / sizeof(menu[0]));

        printf("Enter choice: ");
        if (scanf("%d", &ch) != 1) { int c; while ((c = getchar()) != '\n' && c != EOF) {};
            printf("Invalid input.\n"); pause_msg(NULL); continue; }

        switch (ch) {
            case 1: deleteBus(); break;
            case 2: deletePassenger(); break;
            case 3: deleteReservation(); break;
            case 4: return;
            default:
                printf("\nInvalid choice!");
                pause_msg(NULL);
        }
    }
}
