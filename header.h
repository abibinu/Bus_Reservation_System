#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Provide minimal cross-platform replacements for Turbo C functions.
// When compiling with Turbo C / Borland C, prefer the system <conio.h>.
#if defined(__BORLANDC__) || defined(__TURBOC__)
#include <conio.h>
#else
    // Not Turbo: provide fallbacks for modern compilers/platforms.
    #ifdef _WIN32
        #include <conio.h>
        static void clrscr(void) { system("cls"); }
    #else
        #include <termios.h>
        #include <unistd.h>
        static int getch(void) {
                struct termios oldt, newt;
                int ch;
                tcgetattr(STDIN_FILENO, &oldt);
                newt = oldt;
                newt.c_lflag &= ~(ICANON | ECHO);
                tcsetattr(STDIN_FILENO, TCSANOW, &newt);
                ch = getchar();
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                return ch;
        }
        static void clrscr(void) { printf("\033[H\033[J"); fflush(stdout); }
    #endif
#endif

// ================= STRUCT DEFINITIONS =================

// BUS
struct Bus {
    int b_id;
    char b_name[20];
    char b_from[20];
    char b_to[20];
    int b_seats;
    int b_fare;
};

// PASSENGER
struct Passenger {
    int p_id;
    char p_name[20];
    char p_addr[40];
};

// RESERVATION
struct Reservation {
    int r_id;
    int b_id;
    int p_id;
    char r_date[10];
    int r_seats;
};

// ================= FUNCTION DECLARATIONS =================

// Insert team
void insertBus();
void insertPassenger();
void insertReservation();

// Delete team
void deleteBus();
void deletePassenger();
void deleteReservation();

// Update team
void updateBus();
void updatePassenger();
void updateReservation();

// View team
void viewBus();
void viewPassenger();
void viewReservation();

// Sub-menus
void insertionMenu();
void deletionMenu();
void updationMenu();
void viewMenu();

// UI helpers
void print_banner(const char *title);
void print_menu(const char *options[], int count);
void pause_msg(const char *msg);

#endif
