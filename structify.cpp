// structify.cpp
#include "structify.h"
#include <iomanip>

// ==== User Base Class ====
void User::setUsername(const std::string& name) {
    username = name;
}

// ==== Guest Implementation ====
void Guest::dashboard() {
    clearScreen();
    int choice;
    do{
        std::cout << "\nWelcome Guest, " << username << "!" << std::endl;
        std::cout << "\n\n===== Student Menu =====\n\n" << std::endl;
        std::cout << "[1] Visualize Algorithm\n[2] Visualize Data Structure\n[3] Recursion Visualizer\n[4] Logout\n>> ";
        std::cin >> choice;
        switch (choice) {
            case 1: visualizeAlgorithm(); break;
            case 2: visualizeDataStructure(); break;
            case 3: recursionVisualizer(); break;
            default: std::cout << "Logging out...\n"; break;
        }
        system("pause");
        clearScreen();
    }while(choice != 4);
    
}

void Guest::visualizeAlgorithm() {
    std::cout << "\nChoose Algorithm:\n[1] Bubble Sort\n[2] Selection Sort\n>> ";
    int algChoice;
    std::cin >> algChoice;

    std::cout << "Use:\n[1] Predefined Data\n[2] Custom Input\n>> ";
    int dataChoice;
    std::cin >> dataChoice;

    std::vector<int> data;
    if (dataChoice == 1) {
        data = loadDataFromFile("data.txt");
    } else {
        data = getUserInputData();
    }

    switch (algChoice) {
        case 1: bubbleSort(data); break;
        case 2: selectionSort(data); break;
        default: std::cout << "Invalid Algorithm Selected\n";
    }
}

void Guest::visualizeDataStructure() {
    std::cout << "\n[1] Stack\n[2] Binary Tree\n>> ";
    int choice;
    std::cin >> choice;
    if (choice == 1) visualizeStack();
    else if (choice == 2) visualizeBinaryTree();
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
    std::cout << "[1] View System Logs\n[2] Manage Datasets\n[3] Logout\n>> ";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: viewSystemLogs(); break;
        case 2: manageDatasets(); break;
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
void bubbleSort(std::vector<int>& data, bool showSteps) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }
        if (showSteps) {
            std::cout << "Step " << i + 1 << ": ";
            printVector(data);
        }
    }
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
