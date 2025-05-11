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
    cout << "\n\n\n\n";
    cout << "\t\t\t\tx────────────────────────────────────────────x\n";
    cout << "\t\t\t\t│                                            │\n";
    cout << "\t\t\t\t│             WELCOME TO STRUCTIFY           │\n";
    cout << "\t\t\t\t│                                            │\n";
    cout << "\t\t\t\tx─────────────────Main Menu──────────────────x\n";
    
    const int menuWidth = 41; 

    for(int i = 0; i < optionCount; i++) {
    string item = UserMenuOptions[i];
    string arrow = (i == highlight) ? ">" : " ";
    
    if (i == highlight) {
        setColor(FOREGROUND_GREEN); // White text on blue bg
    } else {
        setColor(7); // Default gray
    }

    // Print the full line including left and right borders and padding
    cout << "\t\t\t\t│ " << arrow << " " 
         << left << setw(menuWidth) << item 
         << "│" << endl;
    }
    setColor(7); 
    cout << "\t\t\t\tx────────────────────────────────────────────x\n";
    cout << "\n\t\t\t\tNavigate with UP/DOWN key, ENTER to select.\n\n";
}
int main() {
    system("chcp 65001 > nul"); //To enable UTF-8 on Windows CMD
    int userType;

    int key;

    while(true){
        displayMenu(selected);
        key = _getch();

        if(key == 224){
            key = _getch();
            if(key == 72 && selected > 0)
                selected--;
            else if(key == 80 && selected < optionCount - 1)
                selected++;
        }
        else if( key == 13){
            system("cls");
            cout << "You selected: " << UserMenuOptions[selected] << endl;
            setColor(7); 
            if (UserMenuOptions[selected] == "Guest (Student)"){
                userType = 1;
                break;
            }else if(UserMenuOptions[selected] == "Admin (Instructor)"){
                userType = 2;
                break;
            }
            else{
                break;
            }
            system("pause");
        }
    }
    

    string name;
    cout << "Enter your name: ";
    cin >> name;

    User* user = nullptr;

    if (userType == 1) {
        user = new Guest();
    } else if (userType == 2) {
        user = new Admin();
    } else {
        cout << "Invalid user type. Exiting...\n";
        return 1;
    }

    user->setUsername(name);
    user->dashboard();

    cout << "\nPress any key to exit...\n";
    _getch();

    delete user;
    cout << "Thank you for using Structify!\n"; 
    return 0;
}
