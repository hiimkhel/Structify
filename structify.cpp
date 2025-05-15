// structify.cpp
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "structify.h"
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include<vector>
#include <fstream>
#include <cmath>
#include <iostream>

#undef byte

using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// ==== Menu UI ====
int showMenuVisualize(const string& title, const vector<string>& options){
    int selected = 0;
    while(true){
        clearScreen();
        system("cls");
    cout << "x───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────x\n";
    cout << "│                                                    ███████╗████████╗██████╗ ██╗   ██╗██████╗ ████████╗██╗███████╗██╗   ██╗                                            │\n";
    cout << "│                                                    ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗╚══██╔══╝██║██╔════╝╚██╗ ██╔╝                                            │\n";
    cout << "│                                                    ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║█████╗   ╚████╔╝                                             │\n";
    cout << "│                                                    ╚════██║   ██║   ██╔═ ██╝██║   ██║██║  ██╗   ██║   ██║██╔══╝    ╚██╔╝                                              │\n";
    cout << "│                                                    ███████╗   ██║   ██║  ██╗╚██████╔╝╚██████║   ██║   ██║██║        ██║                                               │\n";
    cout << "|                                                    ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝╝   ╚═╝   ╚═╝╚═╝        ╚═╝                                               │\n";
    cout << "x─────────────────────────────────────────────────────────────────────────────User Dashboard────────────────────────────────────────────────────────────────────────────x\n";

    cout <<"\t\t\t\t" << title << "\n\n";    
        for(int i = 0; i < options.size(); i++){
            cout << (i == selected ? "\t\t\t\t  > " : "\t\t\t\t  ") << options[i] << "\n";
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
int showMenuAlgorithms(const string& title, const vector<string>& options){
    int selected = 0;
    while(true){
        clearScreen();
        system("cls");
    cout << "x───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────x\n";
    cout << "│                                                    ███████╗████████╗██████╗ ██╗   ██╗██████╗ ████████╗██╗███████╗██╗   ██╗                                            │\n";
    cout << "│                                                    ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗╚══██╔══╝██║██╔════╝╚██╗ ██╔╝                                            │\n";
    cout << "│                                                    ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║█████╗   ╚████╔╝                                             │\n";
    cout << "│                                                    ╚════██║   ██║   ██╔═ ██╝██║   ██║██║  ██╗   ██║   ██║██╔══╝    ╚██╔╝                                              │\n";
    cout << "│                                                    ███████╗   ██║   ██║  ██╗╚██████╔╝╚██████║   ██║   ██║██║        ██║                                               │\n";
    cout << "|                                                    ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝╝   ╚═╝   ╚═╝╚═╝        ╚═╝                                               │\n";
    cout << "x──────────────────────────────────────────────────────────────────────────Sorting Algorithms Menu──────────────────────────────────────────────────────────────────────x\n";
        cout << "\t\t\t\t"<< title << "\n\n";    
        for(int i = 0; i < options.size(); i++){
            cout << (i == selected ? " \t\t\t\t > " : "\t\t\t\t ") << options[i] << "\n";
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

// ==== Helper Functions ====
// Dataset Options
vector<string> getAvailableDatasets() {
    return {
        "unsorted10.txt",
        "unsorted20.txt",
        "unsorted50.txt"
    };
}
string promptDatasetFile() {
    vector<string> datasets = getAvailableDatasets();
    int choice = showMenuVisualize("Choose a dataset to use:", datasets);
    return datasets[choice];
}
//Algorithms
void drawStack(const vector<int>& stackVec, bool showTopLabel = true){
    system("cls");
    cout << " --- Stack Visualization (Top to Bottom) ---\n\n";

    if(stackVec.empty()){
        cout << "[Empty Stack]\n";
        return;
    }

    for(int i = stackVec.size() - 1; i >= 0; --i){
        cout << "    +--------+\n";
        cout << "    |   " << stackVec[i];

        if(stackVec[i] < 10) cout << "    ";
        else if(stackVec[i] < 100 ) cout << "   ";
        else cout << " ";

        cout << "|";

        if(i == stackVec.size() - 1 && showTopLabel)
            cout << "  <-- Top";
        
        cout << "\n    +--------+\n";
    }
}

int partition(vector<int>& data, int low, int high) {
    int pivot = data[high];
    int i = (low - 1);
    for (int j = low; j < high; ++j) {
        if (data[j] <= pivot) {
            ++i;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return (i + 1);
}

void merge(vector<int>& data, int left, int mid, int right, bool showSteps, bool manualSteps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);
    
    for (int i = 0; i < n1; ++i) leftArr[i] = data[left + i];
    for (int j = 0; j < n2; ++j) rightArr[j] = data[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            data[k] = leftArr[i];
            ++i;
        } else {
            data[k] = rightArr[j];
            ++j;
        }
        ++k;
        if (showSteps) {
            printBarChart(data);
            if (manualSteps) {
                cout << "Press any key to continue...\n";
                _getch();
            } else {
                Sleep(800);
            }
        }
    }
    while (i < n1) {
        data[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        data[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSortHelper(vector<int>& data, int left, int right, bool showSteps, bool manualSteps) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(data, left, mid, showSteps, manualSteps);
        mergeSortHelper(data, mid + 1, right, showSteps, manualSteps);
        merge(data, left, mid, right, showSteps, manualSteps);
    }
}
//DSA
void drawQueue(const vector<int>& queueVec) {
    system("cls");
    cout << "   --- Queue Visualization (Front to Rear) ---\n\n";

    if (queueVec.empty()) {
        cout << "[Empty Queue]\n";
        return;
    }

    const int boxWidth = 8;  // Standard box width for consistent spacing
    const string boxTop = "+--------+";

    // Top of boxes
    for (size_t i = 0; i < queueVec.size(); ++i)
        cout << boxTop << " ";
    cout << "\n";

    // Contents of boxes
    for (int val : queueVec) {
        cout << "|  ";
        cout << setw(3) << val << "   | ";
    }
    cout << "\n";

    // Bottom of boxes
    for (size_t i = 0; i < queueVec.size(); ++i)
        cout << boxTop << " ";
    cout << "\n";

    // Indicator line
    for (size_t i = 0; i < queueVec.size(); ++i) {
        if (i == 0)
            cout << setw(boxTop.size()) << "Front" << " ";
        else if (i == queueVec.size() - 1)
            cout << setw(boxTop.size()) << "   Rear" << " ";
        else
            cout << setw(boxTop.size()) << " " << " ";
    }
    cout << "\n";
}


// ==== User Base Class ====
void User::setUsername(const std::string& name) {
    username = name;
}

// ==== Guest Implementation ====
void Guest::dashboard() {
    clearScreen();
    int choice = 0;
    

        vector<string> options = {
            "[1] Visualize Algorithm",
            "[2] Visualize Data Structure",
            "[3] Recursion Visualizer",
            "[4] Logout"
        };
        
        choice = showMenuVisualize("Visualizer Menu:", options);


        clearScreen();
        switch (choice) {
            case 0: visualizeAlgorithm(); break;
            case 1: visualizeDataStructure(); break;
            case 2: recursionVisualizer(); break;
            case 3: std::cout << "Logging out...\n"; break;
        }

    
    
}


void Guest::visualizeAlgorithm() {
     while (true) {
        vector<string> algoOptions ={
            "[1] Bubble Sort",
            "[2] Selection Sort",
            "[3] Insertion Sort",
            "[4] Quick Sort",
            "[5] Merge Sort",
            "[6] Return" 
        };
        int algChoice = showMenuAlgorithms("Choose Algorithm: ", algoOptions);
        if (algChoice == 5) return; 

        vector<string> dataOptions = {
            "[1] Predefined Data",
            "[2] Custom Input",
            "[3] Return"
        };
        int dataChoice = showMenuAlgorithms("Use: ", dataOptions);

        if (dataChoice == 2) continue; 

        vector<int> data;
        string filename = promptDatasetFile();
        if (dataChoice == 0) {
            data = loadDataFromFile(filename);
        } else if (dataChoice == 1) {
            data = getUserInputData();
        }

        bool manualMode = (showMenuAlgorithms("Choose Step Mode:", {"[1] Manual", "[2] Automatic"}) == 0);

        switch (algChoice) {
            case 0: bubbleSort(data, true, manualMode); break;
            case 1: selectionSort(data, true, manualMode); break;
            case 2: insertionSort(data, true, manualMode); break;
            case 3: quickSort(data, 0, data.size() - 1, true, manualMode); break;
            case 4: mergeSort(data, true, manualMode); break;
            default: std::cout << "Invalid Algorithm Selected\n";
        }

        std::cout << "\nPress any key to choose another algorithm or return...\n";
        _getch();
    }
}

void Guest::visualizeDataStructure() {
    while (true) {
        vector<string> structOptions = {
            "[1] Stack",
            "[2] Queue",
            "[3] Linked List",
            "[4] Return"
        };
        int structChoice = showMenuAlgorithms("Choose Data Structure: ", structOptions);
        if (structChoice == 3) return; 

        vector<string> dataOptions = {
            "[1] Predefined Data",
            "[2] Custom Input",
            "[3] Return"
        };
        int dataChoice = showMenuAlgorithms("Use: ", dataOptions);
        if (dataChoice == 2) continue; 

        vector<int> data;
        string filename = promptDatasetFile();
        if (dataChoice == 0) {
            data = loadDataFromFile(filename);
        } else if (dataChoice == 1) {
            data = getUserInputData();
        }

        switch (structChoice) {
            case 0:
                visualizeStack(data);
                break;
            case 1:
                visualizeQueue(data);
                break;
            case 2:
                visualizeLinkedList(data);
                break;
            case 3:
                visualizeBinaryTree(data);
                break;
            default:
                std::cout << "Invalid Data Structure Selected\n";
        }

        std::cout << "\nPress any key to continue...\n";
        _getch();
    }
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

    int choice = showMenuVisualize("Admin Dashboard", adminOptions);

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

void insertionSort(vector<int>& data, bool showSteps, bool manualSteps) {
    int n = data.size();
    for (int i = 1; i < n; ++i) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
            if (showSteps) {
                printBarChart(data, j, j + 1);
                if (manualSteps) {
                    cout << "Press any key to continue...\n";
                    _getch();
                } else {
                    Sleep(800);
                }
            }
        }
        data[j + 1] = key;
        if (showSteps) {
            printBarChart(data);
            if (manualSteps) {
                cout << "Press any key to continue...\n";
                _getch();
            } else {
                Sleep(800);
            }
        }
    }
    setConsoleColor(2);
    printBarChart(data);
    cout << "Array is now sorted!\n";
}

void quickSort(vector<int>& data, int low, int high, bool showSteps, bool manualSteps) {
    if (low < high) {
        int pi = partition(data, low, high);  

        if (showSteps) {
            printBarChart(data, pi, pi);  
            cout << "Pivot is " << data[pi] << "\n";
            if (manualSteps) {
                cout << "Press any key to continue...\n";
                _getch();
            } else {
                Sleep(800);
            }
        }

        quickSort(data, low, pi - 1, showSteps, manualSteps);
        quickSort(data, pi + 1, high, showSteps, manualSteps);
    }
}

void mergeSort(vector<int>& data, bool showSteps, bool manualSteps) {
    mergeSortHelper(data, 0, data.size() - 1, showSteps, manualSteps);

    printBarChart(data, -1, -1); 
    setConsoleColor(10); // Green
    std::cout << "\nArray successfully sorted using Merge Sort!\n";
    setConsoleColor(7);  // Reset
}
// ==== Data Structures Visuals ====
void visualizeQueue(const vector<int>& data){
    vector<int> queueVec;

    // Enqueue phase
    for (size_t i = 0; i < data.size(); ++i) {
        cout << "Press any key to enqueue " << data[i] << "...\n";
        Sleep(500);
        queueVec.push_back(data[i]);
        drawQueue(queueVec);
    }

    cout << "\nAll elements enqueued. Press any key to begin dequeuing...\n";
    _getch();

    // Dequeue phase
    while (!queueVec.empty()) {
        drawQueue(queueVec);
        cout << "\nPress any key to dequeue front element (" << queueVec.front() << ")...\n";
        Sleep(500);
        queueVec.erase(queueVec.begin()); 
    }

    drawQueue(queueVec);
    cout << "\nQueue is now emptied.\n";
}
void visualizeBinaryTree(const vector<int>& data) {
    cout << "visualize binary Tree\n";
}

void visualizeStack(const vector<int>& data) {
    vector<int> q;

    cout << "\n --- Stack Visualization ---\n";
     for (size_t i = 0; i < data.size(); ++i) {
        cout << "Press any key to push " << data[i] << "...\n";
        Sleep(500);
        q.push_back(data[i]);
        drawStack(q);
    }

    cout << "\nAll elements pushed. Press any key to begin popping...\n";
    _getch();

    // Pop phase with animation
    while (!q.empty()) {
        drawStack(q);
        cout << "\nPress any key to pop top element (" << q.back() << ")...\n";
        Sleep(500);
        q.pop_back();
    }

    // Final state
    drawStack(q);
    cout << "\nStack is now emptied.\n";
}
void visualizeLinkedList(const vector<int>& data){
    system("cls");
    cout << "\n--- Linked List Visualization\n";
    
    //Each node will have two pointer; head and tail
    Node* head = nullptr;
    Node* tail = nullptr;

    for(int val : data){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
   
    cout << "\n Traversing Linked List: \n";
    Node* current = head;
    while(current){
        cout << " [" << current->data << "][]-> ";
        current = current->next;
        Sleep(500);
    }
    cout << "NULL\n";


    current = head;
    while(current){
        Node* temp = current;
        current = current->next;
        delete temp;
    }

}
// ==== Patterns Implementation ====
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


