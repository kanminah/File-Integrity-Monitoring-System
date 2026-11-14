#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 

using namespace std;

int main() {
    string myFile = "C:\\Users\\KHAN\\Documents\\fileintegritymonitor\\test.txt.txt";
    long long oldCode = 0; 
    int checkCount = 1; 

    ifstream file1(myFile.c_str()); 
    
    if (!file1.is_open()) {
        cout << "ERROR: Cannot find test.txt!" << endl;
        return 1; 
    }

    char ch1;
    while (file1.get(ch1)) {
        oldCode = oldCode + (int)ch1; 
    }
    file1.close(); 

    cout << "Monitoring started... Go change the file now!" << endl;

    while (true) {
        Sleep(2000); 

        long long currentCode = 0;
        ifstream file2(myFile.c_str()); 

        if (file2.is_open()) {
            char ch2;
            while (file2.get(ch2)) {
                currentCode = currentCode + (int)ch2;
            }
            file2.close();

            if (currentCode != oldCode) {
            	Beep(1000, 1000);
                cout << "[!] ALERT: FILE CHANGED!" << endl;
                oldCode = currentCode; 
            } 
            else {
                cout << "Check #" << checkCount << ": File is safe..." << endl;
                checkCount++;
            }
        }
         if (checkCount % 5 == 0) { 
            char choice;
            cout << "\nKeep monitoring? (y/n): ";
            cin >> choice;

            if (choice == 'n' || choice == 'N') {
                cout << "Exiting program. Goodbye!" << endl;
                break; 
            }
            cout << "Resuming scan...\n" << endl;
        }
    }

    return 0;
}
