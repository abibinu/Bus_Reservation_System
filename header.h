#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

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

#endif
