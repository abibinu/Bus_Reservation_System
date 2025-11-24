#include "header.h"

void updateBus() {
    FILE *fp;
    struct Bus b;
    int id, found = 0;
    print_banner("UPDATE BUS DETAILS");

    printf("Enter Bus ID to update: ");
    scanf("%d", &id);

    fp = fopen("bus.dat", "r+b");
    if (fp == NULL) {
        printf("\nBus data not available!");
        pause_msg(NULL);
        return;
    }

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.b_id == id) {
            found = 1;

            printf("\nCurrent Details:");
            printf("\nName: %s", b.b_name);
            printf("\nFrom: %s", b.b_from);
            printf("\nTo: %s", b.b_to);
            printf("\nSeats: %d", b.b_seats);
            printf("\nFare: %d", b.b_fare);

            printf("\n\nEnter New Details:");

            printf("\nEnter New Bus Name: ");
            scanf("%s", b.b_name);

            printf("Enter New Source: ");
            scanf("%s", b.b_from);

            printf("Enter New Destination: ");
            scanf("%s", b.b_to);

            printf("Enter New Seats: ");
            scanf("%d", &b.b_seats);

            printf("Enter New Fare: ");
            scanf("%d", &b.b_fare);

            // Move pointer back & overwrite
            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);

            printf("\nBus updated successfully!\n");
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("\nBus ID not found!\n");

    pause_msg(NULL);
}

void updatePassenger() {
    FILE *fp;
    struct Passenger p;
    int id, found = 0;
    print_banner("UPDATE PASSENGER DETAILS");

    printf("Enter Passenger ID to update: ");
    scanf("%d", &id);

    fp = fopen("passenger.dat", "r+b");
    if (fp == NULL) {
        printf("\nPassenger data not available!");
        pause_msg(NULL);
        return;
    }

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.p_id == id) {
            found = 1;

            printf("\nCurrent Details:");
            printf("\nName: %s", p.p_name);
            printf("\nAddress: %s", p.p_addr);

            printf("\n\nEnter New Details:");

            printf("\nEnter New Name: ");
            scanf("%s", p.p_name);

            printf("Enter New Address: ");
            scanf("%s", p.p_addr);

            fseek(fp, -sizeof(p), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);

            printf("\nPassenger updated successfully!\n");
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("\nPassenger ID not found!\n");

    pause_msg(NULL);
}

void updateReservation() {
    FILE *fpRes, *fpBus;
    struct Reservation r;
    struct Bus b;
    int id, found = 0;
    print_banner("UPDATE RESERVATION");

    printf("Enter Reservation ID to update: ");
    scanf("%d", &id);

    fpRes = fopen("reservation.dat", "r+b");
    if (fpRes == NULL) {
        printf("\nNo reservations available to update!");
        pause_msg(NULL);
        return;
    }

    while (fread(&r, sizeof(r), 1, fpRes)) {
        if (r.r_id == id) {
            found = 1;

            int oldSeats = r.r_seats;

            printf("\nCurrent Reservation:");
            printf("\nDate: %s", r.r_date);
            printf("\nSeats Reserved: %d", r.r_seats);

            printf("\n\nEnter New Date: ");
            scanf("%s", r.r_date);

            printf("Enter New Number of Seats: ");
            scanf("%d", &r.r_seats);

            // Update seats in bus.dat
            fpBus = fopen("bus.dat", "r+b");
            while (fread(&b, sizeof(b), 1, fpBus)) {
                if (b.b_id == r.b_id) {

                    // return old seats
                    b.b_seats += oldSeats;

                    // check if enough now
                    if (r.r_seats > b.b_seats) {
                        printf("\nNot enough seats available!");
                        fclose(fpBus);
                        fclose(fpRes);
                        pause_msg(NULL);
                        return;
                    }

                    // subtract new seats
                    b.b_seats -= r.r_seats;

                    fseek(fpBus, -sizeof(b), SEEK_CUR);
                    fwrite(&b, sizeof(b), 1, fpBus);
                    break;
                }
            }
            fclose(fpBus);

            // update reservation
            fseek(fpRes, -sizeof(r), SEEK_CUR);
            fwrite(&r, sizeof(r), 1, fpRes);

            printf("\nReservation updated successfully!\n");
            break;
        }
    }

    fclose(fpRes);

    if (!found)
        printf("\nReservation ID not found!\n");

    pause_msg(NULL);
}

void updationMenu() {
    int ch;

    while (1) {
        const char *menu[] = {
            "1. Update Bus",
            "2. Update Passenger",
            "3. Update Reservation",
            "4. Back"
        };

        print_banner("UPDATE MENU");
        print_menu(menu, sizeof(menu) / sizeof(menu[0]));

        printf("Enter choice: ");
        if (scanf("%d", &ch) != 1) { int c; while ((c = getchar()) != '\n' && c != EOF) {};
            printf("Invalid input.\n"); pause_msg(NULL); continue; }

        switch (ch) {
            case 1: updateBus(); break;
            case 2: updatePassenger(); break;
            case 3: updateReservation(); break;
            case 4: return;
            default:
                printf("\nInvalid choice!");
                pause_msg(NULL);
        }
    }
}
