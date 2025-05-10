// structify.cpp
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "structify.h"
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include<vector>
#include <iostream>

#undef byte

using namespace std;

// ==== Menu UI ====
int showMenu(const string& title, const vector<string>& options){
    int selected = 0;
    while(true){
        clearScreen();
        cout << title << "\n\n";
        for(int i = 0; i < options.size(); i++){
            cout << (i == selected ? "  > " : "  ") << options[i] << "\n";
        }

        int key = _getch();
        if(key == 224){
            key = _getch();
            if(key == 72 && selected > 0) selected --;
            else if(key == 80 && selected < options.size() - 1) selected++;
        }else if(key == 13){
            return selected;
        }

    }
}
// ====User Interface Functions ====

//Function for setting color of text
void setConsoleColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printBarChart(const vector<int> data, int highlight1 = -1, int highlight2 = -1){
    system("cls");
    cout <<"Current Array State: \n\n";

    for(int i = 0; i < data.size(); ++i){
        if(i == highlight1 || 1 == highlight2)
            setConsoleColor(6);
        else{
            setConsoleColor(7);
        }
        cout << setw(2) << data[i] << " | ";
        for(int j = 0; j < data[i]; ++j){
            cout<< "#";
        }
        cout << endl;
    }

    setConsoleColor(7);
    cout << endl;
}


// ==== User Base Class ====
void User::setUsername(const std::string& name) {
    username = name;
}

// ==== Guest Implementation ====
void Guest::dashboard() {
    clearScreen();
    int choice = 0;

    while (choice != 3) {
        clearScreen();
        vector<string> options = {
            "[1] Visualize Algorithm",
            "[2] Visualize Data Structure",
            "[3] Recursion Visualizer",
            "[4] Logout"
        };
        
        choice = showMenu("User Dashboard", options);


        clearScreen();
        switch (choice) {
            case 0: visualizeAlgorithm(); break;
            case 1: visualizeDataStructure(); break;
            case 2: recursionVisualizer(); break;
            case 3: std::cout << "Logging out...\n"; break;
        }

        if (choice != 4) {
            std::cout << "\nPress any key to return to the dashboard...";
            setConsoleColor(7);
            _getch();
        }
    }
}


void Guest::visualizeAlgorithm() {
    vector<string> algoOptions ={
        "[1] Bubble Sort",
        "[2] Selection Sort",
        "[3] Return" 
    };
    int algChoice = showMenu("Choose Algorithm: ", algoOptions);
    
    vector<string> dataOptions = {
        "[1] Predefined Data",
        "[2] Custom Input",
        "[3] Return"
    };
    int dataChoice = showMenu("Use: ", dataOptions);
    cout <<"Algorithm choice: " << algChoice << endl;
    cout <<"Data input choice: " << dataChoice << endl;
    
    std::vector<int> data;
    if (dataChoice == 0) {
        data = loadDataFromFile("data.txt");
    } else {
        data = getUserInputData();
    }

    switch (algChoice) {
        case 0: bubbleSort(data, true); break;
        case 1: selectionSort(data, true); break;
        default: std::cout << "Invalid Algorithm Selected\n";
    }
}

void Guest::visualizeDataStructure() {
    vector<string> structureOptions = {
        "[1] Stack",
        "[2] Binary Tree",
        "[3] Return"
    };

    int choice = showMenu("Choose Data Structure: ", structureOptions);
  
    if (choice == 0) visualizeStack();
    else if (choice == 1) visualizeBinaryTree();
    else std::cout << "Invalid option\n";
}

void Guest::recursionVisualizer() {
    std::cout << "Enter number for factorial visualization: ";
    int n;
    std::cin >> n;
    visualizeFactorial(n);
}

// ==== Admin Implementation ====
void Admin::dashboard() {
    clearScreen();
    std::cout << "\nWelcome Admin, " << username << "!" << std::endl;
    vector<string> adminOptions = {
        "[1] View System Logs",
        "[2] Manage Datasets",
        "[3] Logout",
    };

    int choice = showMenu("Admin Dashboard", adminOptions);

    switch (choice) {
        case 0: viewSystemLogs(); break;
        case 1: manageDatasets(); break;
        default: std::cout << "Logging out...\n"; break;
    }
}

void Admin::viewSystemLogs() {
    std::cout << "Viewing system logs (simulated)...\n";
    // Add log viewing logic here
}

void Admin::manageDatasets() {
    std::cout << "Managing datasets (simulated)...\n";
    // Add dataset management logic here
}

// ==== Utilities Implementation ====
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

std::vector<int> loadDataFromFile(const std::string& filename) {
    std::vector<int> data;
    std::ifstream file(filename);
    int value;
    while (file >> value) {
        data.push_back(value);
    }
    return data;
}

std::vector<int> getUserInputData() {
    std::vector<int> data;
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        data.push_back(val);
    }
    return data;
}

void printVector(const std::vector<int>& data) {
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// ==== Algorithms Implementation ====
void bubbleSort(std::vector<int>& data, bool showSteps, bool manualStep) {
    int n = data.size();

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;

        for(int j = 0; j < n - i - 1; ++j){
            if(showSteps){
                printBarChart(data, j, j + 1);
                cout << "Comparing " << data[j] << " and " << data[j + 1] << "\n";
                if(manualStep){
                    cout << "Press any key to continue...\n";
                    _getch();
                }else{
                    Sleep(800);
                }
            }
            if(data[j] > data [j + 1]){
                swap(data[j], data[j + 1]);
                swapped = true;

                if(showSteps){
                    printBarChart(data, j, j + 1);
                    setConsoleColor(4);
                    cout << "Swapped";
                    setConsoleColor(7);

                    if(manualStep){
                        cout << "Press any key to continue...\n";
                        _getch();
                    }else{
                        Sleep(1000);
                    }
                }
            }
        }
        if(!swapped) break;
    }
    setConsoleColor(2); //set color to green
    printBarChart(data);
   
    cout << "Array is now sorted!\n";

}

void selectionSort(std::vector<int>& data, bool showSteps) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(data[i], data[minIndex]);
        if (showSteps) {
            std::cout << "Step " << i + 1 << ": ";
            printVector(data);
        }
    }
}

// ==== Data Structures Visuals ====
void visualizeBinaryTree() {
    std::cout << "\n   5\n  / \\\n  3   8\n / \\   \\\n1   4   9\n";
}

void visualizeStack() {
    std::cout << "\nStack Top\n--------\n|  3  |\n|  2  |\n|  1  |\n--------\n";
}

// ==== Recursion Implementation ====
void visualizeFactorial(int n, int depth) {
    for (int i = 0; i < depth; ++i) std::cout << "  ";
    std::cout << "factorial(" << n << ")\n";
    if (n == 0 || n == 1) {
        for (int i = 0; i < depth; ++i) std::cout << "  ";
        std::cout << "= 1\n";
    } else {
        visualizeFactorial(n - 1, depth + 1);
        for (int i = 0; i < depth; ++i) std::cout << "  ";
        std::cout << "= " << n << " * factorial(" << n - 1 << ")\n";
    }
}
