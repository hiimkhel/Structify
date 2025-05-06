// main.cpp
#include "structify.h"
#include <iostream>

int main() {
    clearScreen();
    std::cout << "===== Welcome to Structify =====\n";
    int userType;
    std::cout << "Select User Type:\n";
    std::cout << "[1] Guest (Student)\n";
    std::cout << "[2] Admin (Instructor)\n";
    std::cout << "Enter choice: ";
    std::cin >> userType;

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    User* user = nullptr;

    if (userType == 1) {
        user = new Guest();
    } else if (userType == 2) {
        user = new Admin();
    } else {
        std::cout << "Invalid user type. Exiting...\n";
        return 1;
    }

    user->setUsername(name);
    user->dashboard();

    delete user;
    std::cout << "Thank you for using Structify!\n";
    return 0;
}
