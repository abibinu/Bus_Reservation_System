🚌 Bus Reservation System – C Project

A structured team-based project for MCA using Turbo C++

📌 Project Overview

This project is a console-based Bus Reservation System developed in C, designed as part of the MCA academic curriculum. It uses file handling and structures for managing buses, passengers, and reservations.

The project is uniquely developed using a team-split method, where each major operation is handled by a dedicated team (Insertion, Deletion, Updation, View), and each team further divides work across the system’s three tables.

🧑‍🤝‍🧑 Team Structure

The work is divided into 4 Sub-Teams, each responsible for one operation across all tables.

| Sub-Team   | Responsibility            | Members   |
| ---------- | ------------------------- | --------- |
| **Team 1** | Insertion (Add Records)   | 3 members |
| **Team 2** | Deletion (Remove Records) | 3 members |
| **Team 3** | Updation (Edit Records)   | 3 members |
| **Team 4** | View (Display Records)    | 3 members |

Each team has one member responsible for:

Bus Operations

Passenger Operations

Reservation Operations

This makes the project scalable, organized, and beginner-friendly.

🧱 Project Architecture

Your project folder will follow this structure:

Bus_Reservation_System/
│
├── main.c
├── header.h
│
├── insert.c
├── delete.c
├── update.c
├── view.c
│
├── bus.dat
├── passenger.dat
├── reservation.dat
│
└── README.md

Purpose of Each File

main.c → Handles menus & navigation

header.h → Contains all struct definitions & function declarations

insert.c → All insertion functions (Team 1)

delete.c → All deletion functions (Team 2)

update.c → All update/edit functions (Team 3)

view.c → All view/display functions (Team 4)

.dat files → Binary files that store the data

🧩 Database (Using Structs)

The project uses 3 tables created using C structures.

🚌 1. Bus Table (Bus)

| No | Description     | Attribute | Type     |
| -- | --------------- | --------- | -------- |
| 1  | Bus ID          | b_id      | int      |
| 2  | Name            | b_name    | char[20] |
| 3  | From            | b_from    | char[20] |
| 4  | To              | b_to      | char[20] |
| 5  | Number of Seats | b_seats   | int      |
| 6  | Fare            | b_fare    | int      |

🧑‍💼 2. Passenger Table (Passenger)

| No | Description       | Attribute | Type     |
| -- | ----------------- | --------- | -------- |
| 1  | Passenger ID      | p_id      | int      |
| 2  | Passenger Name    | p_name    | char[20] |
| 3  | Passenger Address | p_addr    | char[40] |

🧾 3. Reservation Table (Reservation)

| No | Description    | Attribute | Type     |
| -- | -------------- | --------- | -------- |
| 1  | Reservation ID | r_id      | int      |
| 2  | Bus ID         | b_id      | int      |
| 3  | Passenger ID   | p_id      | int      |
| 4  | Date           | r_date    | char[10] |
| 5  | Seats Reserved | r_seats   | int      |

🗂️ Core Modules & Responsibilities

Below is the exact division of responsibilities for each sub-team.

🔹 Team 1 – Insertion Module (insert.c)

Handles adding new records to:

Bus table → insertBus()

Passenger table → insertPassenger()

Reservation table → insertReservation()

Focus on:

Opening files in a+b mode

Validating unique IDs

Writing using fwrite()

🔹 Team 2 – Deletion Module (delete.c)

Handles deletion of:

Bus → deleteBus()

Passenger → deletePassenger()

Reservation → deleteReservation()

Focus on:

Temporary file method

Rewriting records except the one to delete

Replacing original file

🔹 Team 3 – Updation Module (update.c)

Handles editing of:

Bus → updateBus()

Passenger → updatePassenger()

Reservation → updateReservation()

Focus on:

Searching for the record

Using fseek() to overwrite data

Input validation

🔹 Team 4 – View Module (view.c)

Handles displaying:

All buses → viewBus()

All passengers → viewPassenger()

All reservations → viewReservation()

Focus on:

Reading file using fread() until EOF

Clean, formatted console output

🖥️ Main Menu Structure (User Interface)

Your main.c will show:

========== BUS RESERVATION SYSTEM ==========
1. Insert Records
2. Delete Records
3. Update Records
4. View Records
5. Exit

Each option opens a sub-menu:

Example: Insertion Menu

1. Insert Bus
2. Insert Passenger
3. Insert Reservation
4. Back to Main Menu

🔁 Reservation Workflow

User selects Book Reservation

Enter Bus ID & Passenger ID

System checks seat availability

If available → Record saved

Seats reduced from the bus

Reservation stored in reservation.dat

🧪 Testing Checklist

Before final submission ensure:

 Insertion works for all tables

 Duplicate IDs are handled

 Deletion removes the exact record

 Editing overwrites correctly

 Viewing displays clean tables

 Files are not corrupted

 Reservation reduces available seats

 All menus link correctly

🚀 Future Enhancements (Optional)

You may include in your Viva:

Search by Bus ID / Passenger Name

Sort buses by fare or route

Seat availability chart

Export reports to text files

Add authentication (admin login)
# Bus_Reservation_System
