Bus Reservation System
======================

Overview
--------
A small console-based Bus Reservation System written in C. This project demonstrates basic file-based data storage and simple CRUD operations (create, read, update, delete) for Buses, Passengers, and Reservations.

This repository contains a classic Turbo C++-style program that has been adjusted to also build and run with modern GCC/MinGW toolchains on Windows. The UI was refactored so menus look professional and consistent across modules.

Who this README is for
-----------------------
- Beginners learning C who want a simple, complete example of file I/O and menu-driven programs.
- Developers who want to compile the project either with Turbo C++ (Borland) or a modern compiler (GCC/MinGW).

Project structure
-----------------
- `main.c`           : Program entry and main menu
- `insert.c`         : Functions to add Bus, Passenger, Reservation
- `view.c`           : Functions to view lists of Buses/Passengers/Reservations
- `update.c`         : Functions to update records
- `delete.c`         : Functions to delete records
- `header.h`         : Shared structures, declarations and small cross-platform console helpers
- `ui.c`             : Small UI helpers (`print_banner`, `print_menu`, `pause_msg`)

Data files (created at runtime)
-------------------------------
- `bus.dat`          : Binary file storing `struct Bus` records
- `passenger.dat`    : Binary file storing `struct Passenger` records
- `reservation.dat`  : Binary file storing `struct Reservation` records

Note: These files are binary and not human-readable. Keep backups if you want to preserve data between tests.

Build & Run (modern Windows terminal using MinGW/GCC)
-----------------------------------------------------
Prerequisites:
- Install MinGW or a similar GCC toolchain for Windows.
- Ensure `gcc` is available in your `PATH`.

Open PowerShell and run:

```powershell
Set-Location 'C:\TURBOC3\BIN\Bus_Reservation_System'
# Compile all sources

# Run
.\bus_reservation.exe
```

Behavior:
- The program shows a neat banner and number-based menus.
- Use the menu numbers to navigate (e.g., `1` to add data, `4` to view records, `5` to exit).
- When the program prompts "Press any key to continue...", press any key to continue.

Build & Run (Turbo C++ / Borland C++)
------------------------------------
If you want to compile and run with the Turbo C++ IDE (older Borland compilers), follow these steps:

1. Copy or place all source files (`*.c`, `header.h`) into the Turbo C++ project directory or a folder the IDE uses.
2. If your Turbo IDE requires adding files to a project, add: `main.c`, `insert.c`, `view.c`, `update.c`, `delete.c`, `ui.c`, and `header.h`.
3. Build/Compile from the IDE (Project -> Compile / Build). The source was intentionally left compatible with Turbo C macros: `header.h` checks for Borland/Turbo macros and prefers the system `conio.h` when present.
4. Run the program from the Turbo IDE's Run option.

Important notes for Turbo C++ users:
- The project uses `conio.h` style calls (`getch()`, `clrscr()`). When compiling with Turbo/Borland, the original `conio.h` implementation is used.
- Turbo compilers are old and produce 16-bit DOS programs; IDE behavior (file paths, working directory) might differ from modern Windows terminals. Ensure the working directory contains the `*.dat` files (or none, they'll be created when you add records).

Sample interactive walkthrough (quick test)
------------------------------------------
1. Run the program.
2. Choose `1` (Add):
	- Add a Bus: when prompted enter `Bus ID`, `Name`, `From`, `To`, `Seats`, `Fare`.
3. Choose `1` (Add) -> `2` (Add Passenger):
	- Provide `Passenger ID`, `Name`, `Address`.
4. Choose `1` (Add) -> `3` (Make Reservation):
	- Provide a `Reservation ID`, the `Bus ID` and `Passenger ID` you created, a `Date` (e.g., `24/11/2025`), and number of seats to reserve.
5. Choose `4` (Display Records) and view the Buses/Passengers/Reservations to verify entries.

Common issues & troubleshooting
-------------------------------
- Compiler warnings about unused static helpers in `header.h` are harmless; they exist because the header provides cross-platform fallbacks that may not be used on every platform.
- If the program can't find `*.dat` files, it will create them when you add records.
- If you get unexpected behavior in Turbo C++ (IDE-specific), make sure all files are visible to the project and the working directory is set correctly in the IDE.

License / Attribution
---------------------
This is a simple learning project. There is no specific license file included.

