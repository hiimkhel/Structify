// structify.cpp
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "structify.h"
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include<vector>
#include <fstream>
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
        if(i == highlight1 || i == highlight2)
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
    do{
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
    }while(choice != 3);
    
}


void Guest::visualizeAlgorithm() {
     while (true) {
        vector<string> algoOptions ={
            "[1] Bubble Sort",
            "[2] Selection Sort",
            "[3] Return" 
        };
        int algChoice = showMenu("Choose Algorithm: ", algoOptions);
        if (algChoice == 2) return; 

        vector<string> dataOptions = {
            "[1] Predefined Data",
            "[2] Custom Input",
            "[3] Return"
        };
        int dataChoice = showMenu("Use: ", dataOptions);

        if (dataChoice == 2) continue; 

        vector<int> data;
        if (dataChoice == 0) {
            data = loadDataFromFile("data.txt");
        } else if (dataChoice == 1) {
            data = getUserInputData();
        }

        bool manualMode = (showMenu("Choose Step Mode:", {"[1] Manual", "[2] Automatic"}) == 0);

        switch (algChoice) {
            case 0: bubbleSort(data, true, manualMode); break;
            case 1: selectionSort(data, true, manualMode); break;
            default: std::cout << "Invalid Algorithm Selected\n";
        }

        std::cout << "\nPress any key to choose another algorithm or return...\n";
        _getch();
    }
}

void Guest::visualizeDataStructure() {
    vector<string> structureOptions = {
        "[1] Stack",
        "[2] Binary Tree",
        "[3] Linked List",
        "[4] Return"
    };
    
    int choice = showMenu("Choose Data Structure: ", structureOptions);

    if(choice == 3) return;
    
     vector<string> dataOptions = {
        "[1] Predefined Data",
        "[2] Custom Input",
        "[3] Return"
    };
    int dataChoice = showMenu("Use: ", dataOptions);

    
    vector<int> data;
    if (dataChoice == 0) {
        data = loadDataFromFile("data.txt");
    } else if(dataChoice == 1) {
        data = getUserInputData();
    }else{
        return;
    }

  
    if (choice == 0) visualizeStack();
    else if (choice == 1) visualizeBinaryTree();
    else if(choice == 2) visualizeLinkedList();
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

vector<int> loadDataFromFile(const std::string& filename) {
    vector<int> data;
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Could not open file " << filename << "\n";
        return data;
    }

    int value;
    while (file >> value) {
        data.push_back(value);
    }

    if (data.empty()) {
        cerr << "Error: No valid data found in file.\n";
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
void bubbleSort(std::vector<int>& data, bool showSteps, bool manualSteps) {
    int n = data.size();

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;

        for(int j = 0; j < n - i - 1; ++j){
            if(showSteps){
                printBarChart(data, j, j + 1);
                cout << "Comparing " << data[j] << " and " << data[j + 1] << "\n";
                if(manualSteps){
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
                    cout << "Swapped\n";
                    setConsoleColor(7);

                    if(manualSteps){
                        cout << "Press any key to continue...\n";
                        _getch();
                    }else{
                        Sleep(400);
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

void selectionSort(std::vector<int>& data, bool showSteps, bool manualSteps) {
    int n = data.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        swap(data[i], data[minIndex]);
        if (showSteps) {
            printBarChart(data, i, minIndex);
            setConsoleColor(4);
            cout << "Swapped " << data[i] << " and " << data[minIndex] << endl;
            setConsoleColor(7);
            if(manualSteps){
                cout << "Press any key to continue...\n";
            }else{
                Sleep(800);
            }
        }
    }
    setConsoleColor(2);
    printBarChart(data);
    cout << "Array is now sorted!\n";
    
    setConsoleColor(7);
}

// ==== Data Structures Visuals ====
void visualizeBinaryTree() {
    std::cout << "\n   5\n  / \\\n  3   8\n / \\   \\\n1   4   9\n";
}

void visualizeStack() {
    std::cout << "\nStack Top\n--------\n|  3  |\n|  2  |\n|  1  |\n--------\n";
}
void visualizeLinkedList(){
     system("cls");
    cout << "\n[10] -> [20] -> [30] -> NULL\n\n";
    cout << "Press any key to go back...";
    _getch();
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

//==== Helper Functions ====
vector<int> getUserInputData() {
    vector<int> data;
    int n;
    cout << "Enter number of elements: ";

    while(!(cin >> n) || n <= 0){
        cin.clear();
        cin.ignore(10000, '\n'); //discard invalid input
        cout << "Invalid input. Enter a positive number of elements: ";
    }

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        int val;
        while(!(cin >> val)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter an integer: ";
        }

        data.push_back(val);
    }
    return data;
}

vector<int> randomDataGenerator(int n, int max = 50){
    vector<int> data(n);
    for(int& x: data) x = rand() % max + 1;
    return data;
}
