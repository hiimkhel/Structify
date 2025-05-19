// main.cpp
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include "structify.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
#undef byte

using namespace std;

string UserMenuOptions[] = {"Guest (Student)", "Admin (Instructor)", "EXIT"};
int selected = 0;
int optionCount = sizeof(UserMenuOptions) / sizeof(UserMenuOptions[0]);

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
};

void displayMenu(int highlight){
    system("cls");
    cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                    ███████╗████████╗██████╗ ██╗   ██╗██████╗ ████████╗██╗███████╗██╗   ██╗                                            ║\n";
    cout << "║                                                    ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗╚══██╔══╝██║██╔════╝╚██╗ ██╔╝                                            ║\n";
    cout << "║                                                    ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║█████╗   ╚████╔╝                                             ║\n";
    cout << "║                                                    ╚════██║   ██║   ██╔═ ██╝██║   ██║██║  ██╗   ██║   ██║██╔══╝    ╚██╔╝                                              ║\n";
    cout << "║                                                    ███████╗   ██║   ██║  ██╗╚██████╔╝╚██████║   ██║   ██║██║        ██║                                               ║\n";
    cout << "║                                                    ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝╝   ╚═╝   ╚═╝╚═╝        ╚═╝                                               ║\n";
    cout << "x══════════════════════════════════════════════════════════════════════════════System Overview══════════════════════════════════════════════════════════════════════════x\n";
    cout << "│                                                                                                                                                                       │\n";
    cout << "│  📘 StructiFy is a terminal-based interactive educational toolkit designed to enhance computer science learning, , particularly in the areas of Data Structures       │\n";
    cout << "│     and Algorithms (DSA), Pattern Generation, and Visualization. It provides a unified and engaging experience tailored for beginners and intermediate learners,      │\n";
    cout << "│     making abstract concepts more tangible through structured interaction and visual representation.                                                                  │\n";
    cout << "│                                                                                                                                                                       │\n";
    cout << "x─────────────────────────────────────────────────────────────────────────────────MAIN MENU─────────────────────────────────────────────────────────────────────────────x\n";                                                                                                                                             
    
    const int menuWidth = 153; 

    for(int i = 0; i < optionCount; i++) {
    string item = UserMenuOptions[i];
    string arrow = (i == highlight) ? ">>>" : "   ";
    
    if (i == highlight) {
        setColor(FOREGROUND_GREEN); // White text on blue bg
    } else {
        setColor(7); // Default gray
    }

    // Print the full line including left and right borders and padding
    cout << "│          " << arrow << " " 
         << left << setw(menuWidth) << item 
         << "│" << endl;
    }
    setColor(7); 
   
    cout << "=========================================================================================================================================================================\n";
    cout << "                                                                                                                       (↑)/(↓)=Move           ENTER=Select\n";
    cout << "=========================================================================================================================================================================\n";
}
int main() {
   system("chcp 65001 > nul"); // UTF-8 support

    while (true) {
        int userType;
        int key;

        selected = 0; // Reset highlight
        while (true) {
            displayMenu(selected);
            key = _getch();

            if (key == 224) {
                key = _getch();
                if (key == 72 && selected > 0) selected--;
                else if (key == 80 && selected < optionCount - 1) selected++;
            } else if (key == 13) {
                system("cls");
                setColor(7);
                if (UserMenuOptions[selected] == "Guest (Student)") {
                    userType = 1;
                    break;
                } else if (UserMenuOptions[selected] == "Admin (Instructor)") {
                    userType = 2;
                    break;
                } else {
                    userType = 3;
                    break;
                }
            }
        }

        if (userType == 3) {
            cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
            cout << "║  ████████╗ ██╗  ██╗ ██╗ ███████╗       ██╗  ██║   ██║ ██████╗ ███████╗       ███████╗████████╗██████╗ ██╗   ██╗██████╗ ████████╗██╗███████╗██╗   ██╗     ██╗ ██╗ ██╗  ║\n";
            cout << "║  ╚══██╔══╝ ██╚══██║ ██║ ██╔════╝       ██║  ██║   ██║ ██╔═██║ ██╔════╝       ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗╚══██╔══╝██║██╔════╝╚██╗ ██╔╝     ██║ ██║ ██║  ║\n";
            cout << "║     ██║    ███████║ ██║ ███████╗       ██║  ██║   ██║ ██████║ ███████╗       ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║█████╗   ╚████╔╝      ██║ ██║ ██║  ║\n";
            cout << "║     ██║    ██╔══██║ ██║ ╚════██║       ██   ██║   ██║ ██╔═██║ ╚════██║       ╚════██║   ██║   ██╔═ ██╝██║   ██║██║  ██╗   ██║   ██║██╔══╝    ╚██╔╝       ╚═╝ ╚═╝ ╚═╝  ║\n";
            cout << "║     ██║    ██║  ██║ ██║ ███████╗       ╚████╔╝╚████╔╝ ██║ ██║ ███████╗       ███████╗   ██║   ██║  ██╗╚██████╔╝╚██████║   ██║   ██║██║        ██║        ██║ ██║ ██║  ║\n";
            cout << "║     ╚═╝    ╚═╝  ╚═╝ ╚═╝ ╚══════╝        ╚═══╝  ╚═══╝  ╚═╝ ╚═╝ ╚══════╝       ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝╝   ╚═╝   ╚═╝╚═╝        ╚═╝        ╚═╝ ╚═╝ ╚═╝  ║\n";
            cout << "x═════════════════════════════════════════════Thank you for learning with StructiFy - the future of CS!═════════════════════════════════════════════════════════════════x\n";
            system("pause");
            break; // Exit the outer loop
        }

        system("cls");
        structifyHeader();

        User* user = nullptr;
        string name;

        if (userType == 1) {
            cout << "\t\tEnter your name: ";
            cin >> name;
            user = new Guest();
            user->setUsername(name);
            user->dashboard();
        } else if (userType == 2) {
            string adminName;
            bool authenticated = false;

            for (int attempts = 0; attempts < 3; ++attempts) {
                system("cls");
                if (Admin::authenticate(adminName)) {
                    authenticated = true;
                    break;
                } else {
                    cout << "\n\t\t\t\t[!] Authentication failed. Attempt " << (attempts + 1) << " of 3.\n";
                    cout << "\t\t\t\tPress any key to reattempt.\n";
                    _getch();
                }
            }

            if (authenticated) {
                user = new Admin();
                user->setUsername(adminName);
                user->dashboard(); // Will return control here after logout
            } else {
                char choice;
                cout << "\n\t\t\t\t[!] Too many failed attempts.\n";
                cout << "\t\t\t\tDo you want to return to main menu? (y/n): ";
                cin >> choice;

                if (tolower(choice) != 'y') {
                    cout << "\t\t\t\tExiting program...\n";
                    break;
                }
            }
        }

        delete user;
    }
    
    return 0;
}
