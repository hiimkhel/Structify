// main.cpp
#include "structify.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

string UserMenuOptions[] = {"Guest (Student)", "Admin (Instructor)", "EXIT"};
int selected = 0;
int optionCount = sizeof(UserMenuOptions) / sizeof(UserMenuOptions[0]);

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
};

void displayMenu(int highlight){
    system("cls");
    cout << "===== Welcome to Structify =====\n";
    for(int i = 0; i < optionCount; i++){
        if(i == highlight){
            setColor(15);
            cout << " > " << UserMenuOptions[i] << endl;
        }
        else{
            setColor(8); 
            cout << "  " << UserMenuOptions[i] << endl;
        }
        
        
    }
    setColor(7); 
    cout << "\n\nUse UP/DOWN arrow keys to navigate, ENTER to select.\n\n";
}
int main() {
    
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
            if (UserMenuOptions[selected] == "EXIT") break;
            system("pause");
        }

        
    }



    /*
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

    delete user;
    cout << "Thank you for using Structify!\n"; */
    return 0;
}
