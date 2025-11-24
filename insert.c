#include "header.h"

void insertBus() {
    struct Bus b;
    FILE *fp;
    int idFound = 0;
    struct Bus temp;

    print_banner("INSERT NEW BUS");

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
        pause_msg(NULL);
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
        pause_msg(NULL);
        return;
    }

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("\nBus added successfully!\n");
    pause_msg(NULL);
}

void insertPassenger() {
    struct Passenger p, temp;
    FILE *fp;
    int idFound = 0;

    print_banner("INSERT NEW PASSENGER");

    printf("\nEnter Passenger ID: ");
    scanf("%d", &p.p_id);

    // --- Check for duplicate ---
    fp = fopen("passenger.dat", "rb");
    if (fp != NULL) {
        while (fread(&temp, sizeof(temp), 1, fp)) {
            if (temp.p_id == p.p_id) {
                idFound = 1;
                break;
            }
        }
        fclose(fp);
    }

    if (idFound) {
        printf("\nPassenger ID already exists!");
        pause_msg(NULL);
        return;
    }

    printf("Enter Passenger Name: ");
    scanf("%s", p.p_name);

    printf("Enter Passenger Address: ");
    scanf("%s", p.p_addr);

    // --- Insert into file ---
    fp = fopen("passenger.dat", "ab");
    if (fp == NULL) {
        printf("\nError opening file!");
        pause_msg(NULL);
        return;
    }

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("\nPassenger added successfully!\n");
    pause_msg(NULL);
}

void insertReservation() {
    struct Reservation r;
    struct Bus b;
    struct Passenger p;
    FILE *fpBus, *fpPass, *fpRes;

    int busFound = 0, passFound = 0;

    print_banner("NEW RESERVATION");

    printf("\nEnter Reservation ID: ");
    scanf("%d", &r.r_id);

    // ===== CHECK BUS ID =====
    printf("Enter Bus ID: ");
    scanf("%d", &r.b_id);

    fpBus = fopen("bus.dat", "r+b");
    if (fpBus == NULL) {
        printf("\nBus file missing!");
        pause_msg(NULL);
        return;
    }

    while (fread(&b, sizeof(b), 1, fpBus)) {
        if (b.b_id == r.b_id) {
            busFound = 1;
            break;
        }
    }

    if (!busFound) {
        printf("\nBus ID not found!");
        fclose(fpBus);
        pause_msg(NULL);
        return;
    }

    // ===== CHECK PASSENGER ID =====
    printf("Enter Passenger ID: ");
    scanf("%d", &r.p_id);

    fpPass = fopen("passenger.dat", "rb");
    if (fpPass == NULL) {
        printf("\nPassenger file missing!");
        fclose(fpBus);
        pause_msg(NULL);
        return;
    }

    while (fread(&p, sizeof(p), 1, fpPass)) {
        if (p.p_id == r.p_id) {
            passFound = 1;
            break;
        }
    }
    fclose(fpPass);

    if (!passFound) {
        printf("\nPassenger ID not found!");
        fclose(fpBus);
        pause_msg(NULL);
        return;
    }

    printf("Enter Reservation Date (DD/MM/YYYY): ");
    scanf("%s", r.r_date);

    printf("Enter Number of Seats to Reserve: ");
    scanf("%d", &r.r_seats);

    // ===== CHECK SEAT AVAILABILITY =====
    if (r.r_seats > b.b_seats) {
        printf("\nNot enough seats! Only %d left.", b.b_seats);
        fclose(fpBus);
        pause_msg(NULL);
        return;
    }

    // ===== UPDATE SEATS IN BUS FILE =====
    b.b_seats -= r.r_seats;

    // Move pointer back 1 record
    fseek(fpBus, -sizeof(b), SEEK_CUR);
    fwrite(&b, sizeof(b), 1, fpBus);
    fclose(fpBus);

    // ===== INSERT INTO RESERVATION FILE =====
    fpRes = fopen("reservation.dat", "ab");
    fwrite(&r, sizeof(r), 1, fpRes);
    fclose(fpRes);

    printf("\nReservation successful!\n");
    pause_msg(NULL);
}

void insertionMenu() {
    int ch;

    while (1) {
        const char *menu[] = {
            "1. Add Bus",
            "2. Add Passenger",
            "3. Make Reservation",
            "4. Back"
        };

        print_banner("RECORD ADDITION MENU");
        print_menu(menu, sizeof(menu) / sizeof(menu[0]));

        printf("Enter choice: ");
        if (scanf("%d", &ch) != 1) { int c; while ((c = getchar()) != '\n' && c != EOF) {};
            printf("Invalid input.\n"); pause_msg(NULL); continue; }

        switch (ch) {
            case 1: insertBus(); break;
            case 2: insertPassenger(); break;
            case 3: insertReservation(); break;
            case 4: return;
            default:
                printf("\nInvalid choice!");
                pause_msg(NULL);
        }
    }
}
