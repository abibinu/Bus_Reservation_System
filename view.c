#include "header.h"

void viewBus() {
    FILE *fp;
    struct Bus b;
    int count = 0;
    print_banner("LIST OF BUSES");

    fp = fopen("bus.dat", "rb");
    if (fp == NULL) {
        printf("\nNo bus data available.\n");
        pause_msg(NULL);
        return;
    }

    printf("\n%-10s %-15s %-10s %-10s %-10s %-10s",
           "BusID", "Name", "From", "To", "Seats", "Fare");

    printf("\n--------------------------------------------------------------");

    while (fread(&b, sizeof(b), 1, fp)) {
        printf("\n%-10d %-15s %-10s %-10s %-10d %-10d",
               b.b_id, b.b_name, b.b_from, b.b_to, b.b_seats, b.b_fare);
        count++;
    }

    fclose(fp);
    if (count == 0)
        printf("\n\nNo bus records found.\n");

    pause_msg(NULL);
}

void viewPassenger() {
    FILE *fp;
    struct Passenger p;
    int count = 0;
    print_banner("LIST OF PASSENGERS");

    fp = fopen("passenger.dat", "rb");
    if (fp == NULL) {
        printf("\nNo passenger data available.\n");
        pause_msg(NULL);
        return;
    }

    printf("\n%-10s %-15s %-25s",
           "PassID", "Name", "Address");

    printf("\n------------------------------------------------------");

    while (fread(&p, sizeof(p), 1, fp)) {
        printf("\n%-10d %-15s %-25s",
               p.p_id, p.p_name, p.p_addr);
        count++;
    }

    fclose(fp);
    if (count == 0)
        printf("\n\nNo passenger records found.\n");

    pause_msg(NULL);
}

void viewReservation() {
    FILE *fp;
    struct Reservation r;
    int count = 0;
    print_banner("LIST OF RESERVATIONS");

    fp = fopen("reservation.dat", "rb");
    if (fp == NULL) {
        printf("\nNo reservations found.\n");
        pause_msg(NULL);
        return;
    }

    printf("\n%-10s %-10s %-10s %-15s %-10s",
           "ResID", "BusID", "PassID", "Date", "Seats");

    printf("\n----------------------------------------------------------");

    while (fread(&r, sizeof(r), 1, fp)) {
        printf("\n%-10d %-10d %-10d %-15s %-10d",
               r.r_id, r.b_id, r.p_id, r.r_date, r.r_seats);
        count++;
    }

    fclose(fp);
    if (count == 0)
        printf("\n\nNo reservation records found.\n");

    pause_msg(NULL);
}

void viewMenu() {
    int ch;
    while (1) {
        const char *menu[] = {
            "1. View Buses",
            "2. View Passengers",
            "3. View Reservations",
            "4. Back"
        };

        print_banner("VIEW MENU");
        print_menu(menu, sizeof(menu) / sizeof(menu[0]));

        printf("Enter choice: ");
        if (scanf("%d", &ch) != 1) { int c; while ((c = getchar()) != '\n' && c != EOF) {};
            printf("Invalid input.\n"); pause_msg(NULL); continue; }

        switch (ch) {
            case 1: viewBus(); break;
            case 2: viewPassenger(); break;
            case 3: viewReservation(); break;
            case 4: return;
            default:
                printf("\nInvalid choice!");
                pause_msg(NULL);
        }
    }
}
