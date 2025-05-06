#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

string options[] = {"Option 1", "Option 2", "Option 3", "Exit"};
int selected = 0;
const int optionCount = sizeof(options) / sizeof(options[0]);

// Set console text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void displayMenu(int highlight) {
    system("cls");
    cout << "Use UP/DOWN arrow keys to navigate, ENTER to select.\n\n";
    for (int i = 0; i < optionCount; i++) {
        if (i == highlight) {
            setColor(15);  // Bright white text
            cout << " > " << options[i] << endl;
        } else {
            setColor(8);   // Gray text
            cout << "   " << options[i] << endl;
        }
    }
    setColor(7); // Reset to default color (light gray)
}

int main() {
    int key;
    while (true) {
        displayMenu(selected);
        key = _getch();

        if (key == 224) { // Special key
            key = _getch();
            if (key == 72 && selected > 0)
                selected--;           // Up
            else if (key == 80 && selected < optionCount - 1)
                selected++;          // Down
        } else if (key == 13) { // Enter
            system("cls");
            setColor(10); // Green
            cout << "You selected: " << options[selected] << endl;
            setColor(7); // Reset
            if (options[selected] == "Exit") break;
            system("pause");
        }
    }
    return 0;
}
