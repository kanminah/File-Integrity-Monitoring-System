# File-Integrity-Monitoring-System
A console-based File Integrity Monitoring (FIM) tool built in C++ that tracks file changes and alerts users.

## Features
* **Baseline Hashing:** Calculates an initial checksum value from the contents of the target text file.
* **Continuous Monitoring:** Periodically scans the file at set intervals using Windows sleep timers.
* **Alert Mechanism:** Emits an audible system beep (`Beep`) and prints a notification log when a modification is detected.
* **Interactive Prompts:** Allows users to interactively pause or exit monitoring after a set number of checks.

## Prerequisites
* **Compiler:** A C++ compiler (such as MinGW / Dev-C++ 5.11) supporting Windows API headers.
* **Environment:** Windows Operating System (uses `<windows.h>` for `Sleep` and `Beep`).

## How to Run
1. Clone or download this repository locally.
2. Ensure `main.cpp` and `test.txt` are in the same working directory.
3. Compile and run `main.cpp` using your preferred C++ IDE (like Dev-C++ or Code::Blocks).
4. Modify and save `test.txt` while the program is running to observe the change detection alert.
