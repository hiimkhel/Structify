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
#include <sstream>
#include <ctime>
#include <regex>
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <random>

#undef byte
const int TERMINAL_WIDTH = 168;
using namespace std;
namespace fs = filesystem;
struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
struct Complexity {
    string best;
    string average;
    string worst;
};
// ==== Menu UI ====
//Function for setting color of text
void setConsoleColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void structifyHeader(){
    cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                    ███████╗████████╗██████╗ ██╗   ██╗██████╗ ████████╗██╗███████╗██╗   ██╗                                            ║\n";
    cout << "║                                                    ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗╚══██╔══╝██║██╔════╝╚██╗ ██╔╝                                            ║\n";
    cout << "║                                                    ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║█████╗   ╚████╔╝                                             ║\n";
    cout << "║                                                    ╚════██║   ██║   ██╔═ ██╝██║   ██║██║  ██╗   ██║   ██║██╔══╝    ╚██╔╝                                              ║\n";
    cout << "║                                                    ███████╗   ██║   ██║  ██╗╚██████╔╝╚██████║   ██║   ██║██║        ██║                                               ║\n";
    cout << "║                                                    ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝╝   ╚═╝   ╚═╝╚═╝        ╚═╝                                               ║\n";
    cout << "x═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════x\n";
};
void adminHeader(){
    cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                    ███████╗████████╗██████╗ ██╗   ██╗██████╗ ████████╗██╗███████╗██╗   ██╗                                            ║\n";
    cout << "║                                                    ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗╚══██╔══╝██║██╔════╝╚██╗ ██╔╝                                            ║\n";
    cout << "║                                                    ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║█████╗   ╚████╔╝                                             ║\n";
    cout << "║                                                    ╚════██║   ██║   ██╔═ ██╝██║   ██║██║  ██╗   ██║   ██║██╔══╝    ╚██╔╝                                              ║\n";
    cout << "║                                                    ███████╗   ██║   ██║  ██╗╚██████╔╝╚██████║   ██║   ██║██║        ██║                                               ║\n";
    cout << "║                                                    ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝╝   ╚═╝   ╚═╝╚═╝        ╚═╝                                               ║\n";
    cout << "x════════════════════════════════════════════════════════════════════════════════ADMIN MENU═════════════════════════════════════════════════════════════════════════════x\n";
};
int showMenuVisualize(const string& title, const vector<string>& options){
    int selected = 0;
    while(true){
        system("cls");
    structifyHeader();
    cout << "║                                                                                                                                                                       ║\n";
    cout << "║                                                                                                                                                                       ║\n";
    cout << "║                         [+] Lets explore, learn, and visualize common sorting algorithms, data structures, and pattern logic in a fun and interactive way!!!          ║\n";
    cout << "║                                                                                                                                                                       ║\n";
    cout << "║                                                                                                                                                                       ║\n";
    cout << "╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n";   
    cout <<"\t\t\t\t" << title << "\n\n";    
        for(int i = 0; i < options.size(); i++){
            cout << (i == selected ? "\t\t\t\t>>> " : "\t\t\t\t    ") << options[i] << "\n";
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
        system("cls");
        structifyHeader();
        cout << "║                                                                                                                                                                       ║\n";
        cout << "║          [+] WELCOME TO THE SORTING ALGORITHMS VISUALIZER OF STRUCTIFY! LETS UNDERSTAND WHAT'S BENEATH THE HOOD OF SORTING ALGORITHMS THROUGH OUR VISUALIZATION!      ║\n";
        cout << "║                                                                                                                                                                       ║\n";
        cout << "║  >>> This feature provides a step-by-step visualization of common sorting algorithms, helping students understand and grasp the logic, behaviour, and efficiency,     ║\n";
        cout << "║      one iteration at a time. Structify bridges the gap between theory and implementation with its clear graphical representation and time complexity insights.       ║\n";
        cout << "║                                                                                                                                                                       ║\n";
        cout << "╠═════════════════════════════════════════════════════════════════SORTING ALGORITHMS MENU═══════════════════════════════════════════════════════════════════════════════╣\n";    
        cout << "\t\t\t\t"<< title << "\n\n\n";    
        for(int i = 0; i < options.size(); i++){
            cout << (i == selected ? "\t\t\t\t>>> " : "\t\t\t\t    ") << options[i] << "\n";
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


int showMenuDSA(const string& title, const vector<string>& options){
    int selected = 0;
    while(true){
        system("cls");
    structifyHeader();
    cout << "│                                                                                                                                                                       │\n";
    cout << "│          [+] WELCOME TO THE DATA STUCTURE VISUALIZER OF STRUCTIFY! YOUR INTERACTIVE TOOL FOR EXPLORING HOW FUNDAMENTAL DATA STRUCTURES OPERATE INTERNALLY.            │\n";
    cout << "│                                                                                                                                                                       │\n";
    cout << "│  >>> This feature allows students and developers to visualize dynamic changes in common data structures as elements are added, removed, or manipulated. Structify     │\n";
    cout << "│      makes abstract concepts easily digested and beginner-friendly with its integration of animated operations.                                                       │\n";
    cout << "│                                                                                                                                                                       │\n";
    cout << "x──────────────────────────────────────────────────────────────────────DATA STRUCTURE VISUALIZER MENU───────────────────────────────────────────────────────────────────x\n";     
        cout << "\t\t\t\t"<< title << "\n\n";    
        for(int i = 0; i < options.size(); i++){
            cout << (i == selected ? "\t\t\t\t>>> " : "\t\t\t\t    ") << options[i] << "\n";
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

int patternDifficultyDashboard(const vector<string> options){
    int selected = 0;
    while(true){
        system("cls");
    structifyHeader();
    cout << "│                                                                                                                                                                       │\n";
    cout << "│          [+] WELCOME TO THE PATTERNS GENERATOR OF STRUCTIFY! LETS VISUALIZE THE LOGIC BEHIND EACH LOOP AND EXPERIMENT WITH DIFFERENT VARIATIONS!                      │\n";
    cout << "│                                                                                                                                                                       │\n";
    cout << "│  >>> This feature is designed to help you understand nested loops and logic building through visual pattern generation. Structify makes pattern creation interactive  │\n";
    cout << "│      and intuitive whether you are a beginner or someone who wants to strengthen your loop control skill.                                                             |\n";
    cout << "│                                                                                                                                                                       │\n";
    cout << "x───────────────────────────────────────────────────────────────────────PATTERNS GENERATOR MENU────────────────────────────────────────────────────────────────────────x\n"; 
    for(int i = 0; i < options.size(); i++){
            cout << (i == selected ? "\t\t\t\t>>> " : "\t\t\t\t    ") << options[i] << "\n";
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
int showMenuManageDataset( const vector<string>& options){
    int selected = 0;
    while(true){
        system("cls");
        adminHeader();   
        for(int i = 0; i < options.size(); i++){
            cout << (i == selected ? "\t\t\t\t>>> " : "\t\t\t\t    ") << options[i] << "\n";
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
string wrapText(const string& text, size_t width = 140) {
    string wrapped;
    size_t start = 0;
    while (start < text.length()) {
        size_t end = start + width;
        if (end >= text.length()) {
            wrapped += text.substr(start);
            break;
        }
        size_t spacePos = text.rfind(' ', end);
        if (spacePos == string::npos || spacePos <= start)
            spacePos = end;
        wrapped += text.substr(start, spacePos - start) + "\n";
        start = spacePos + 1;
    }
    return wrapped;
}

int showMenuDataset(const string& title, const vector<string>& options){
    int selected = 0;
    while(true){
        system("cls");
    structifyHeader();
    cout << "│                                                                                                                                                                       │\n";
    cout << "│                         [+] Before we visualize the algorithm, let's choose your data source.                                                                         │\n";
    cout << "│                                                                                                                                                                       │\n";
    cout << "│                              [*] Use a predefined dataset for quick testing and examples.                                                                             │\n";
    cout << "│                              [*] Enter your own custom input for a personalized experience.                                                                           │\n";
    cout << "│                                                                                                                                                                       │\n"; 
    cout << "x─────────────────────────────────────────────────────────────────────────DATASET MENU──────────────────────────────────────────────────────────────────────────────────x\n";   
    cout <<"\t\t\t\t" << title << "\n\n";    
        for(int i = 0; i < options.size(); i++){
            cout << (i == selected ? "\t\t\t\t>>> " : "\t\t\t\t    ") << options[i] << "\n";
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

void algorithmHeader(const string& algoName, const string& algoDescription) {
    unordered_map<string, Complexity> complexityMap = {
        { "BUBBLE SORT", { "O(n)", "O(n^2)", "O(n^2)" } },
        { "SELECTION SORT", { "O(n^2)", "O(n^2)", "O(n^2)" } },
        { "INSERTION SORT", { "O(n)", "O(n^2)", "O(n^2)" } },
        { "MERGE SORT", { "O(n log n)", "O(n log n)", "O(n log n)" } },
        { "QUICK SORT", { "O(n log n)", "O(n log n)", "O(n^2)" } },
        // Add more algorithms as needed
    };
    
    Complexity comp = complexityMap[algoName];
    
    cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                    ███████╗████████╗██████╗ ██╗   ██╗██████╗ ████████╗██╗███████╗██╗   ██╗                                            ║\n";
    cout << "║                                                    ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗╚══██╔══╝██║██╔════╝╚██╗ ██╔╝                                            ║\n";
    cout << "║                                                    ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║█████╗   ╚████╔╝                                             ║\n";
    cout << "║                                                    ╚════██║   ██║   ██╔═ ██╝██║   ██║██║  ██╗   ██║   ██║██╔══╝    ╚██╔╝                                              ║\n";
    cout << "║                                                    ███████╗   ██║   ██║  ██╗╚██████╔╝╚██████║   ██║   ██║██║        ██║                                               ║\n";
    cout << "║                                                    ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝╝   ╚═╝   ╚═╝╚═╝        ╚═╝                                               ║\n";
    cout << "x═══════════════════════════════════════════════════════════════════════SORTING ALGORITHM VISUALIZER════════════════════════════════════════════════════════════════════x\n\n";
    cout << "           [ SORTING ALGORITHM: " << algoName << " ]\n";
    cout << "========================================================================================================================================================================\n";
    cout << " \n  [*] DESCRIPTION: \n\n";
    cout << "       " << wrapText(algoDescription) << " \n";
cout << "========================================================================================================================================================================\n";
    cout << "\n  [*] TIME COMPLEXITY:\n\n";
    cout << "      [O] Best Case:    " << comp.best << "\n";
    cout << "      [Θ] Average Case: " << comp.average << "\n";
    cout << "      [Ω] Worst Case:   " << comp.worst << "\n";
    cout << "========================================================================================================================================================================\n";
}

void dataStructHeader(const string& dataStructName, const string& dataStructDescription){
    cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                    ███████╗████████╗██████╗ ██╗   ██╗██████╗ ████████╗██╗███████╗██╗   ██╗                                            ║\n";
    cout << "║                                                    ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗╚══██╔══╝██║██╔════╝╚██╗ ██╔╝                                            ║\n";
    cout << "║                                                    ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║█████╗   ╚████╔╝                                             ║\n";
    cout << "║                                                    ╚════██║   ██║   ██╔═ ██╝██║   ██║██║  ██╗   ██║   ██║██╔══╝    ╚██╔╝                                              ║\n";
    cout << "║                                                    ███████╗   ██║   ██║  ██╗╚██████╔╝╚██████║   ██║   ██║██║        ██║                                               ║\n";
    cout << "║                                                    ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝╝   ╚═╝   ╚═╝╚═╝        ╚═╝                                               ║\n";
    cout << "x══════════════════════════════════════════════════════════════════════════DATA STRUCTURE VISUALIZER════════════════════════════════════════════════════════════════════x\n";
    cout << "\n\n       [ DATA STRUCTURE: "<< dataStructName << " ]\n";
    cout << "========================================================================================================================================================================\n";
    cout << " \n     DESCRIPTION: \n\n";
    cout << "       [+] " << wrapText(dataStructDescription) << " \n";
    cout << "========================================================================================================================================================================\n";
}

void patternHeader(const string& patternName, const string& level){
    cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                    ███████╗████████╗██████╗ ██╗   ██╗██████╗ ████████╗██╗███████╗██╗   ██╗                                            ║\n";
    cout << "║                                                    ██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔══██╗╚══██╔══╝██║██╔════╝╚██╗ ██╔╝                                            ║\n";
    cout << "║                                                    ███████╗   ██║   ██████╔╝██║   ██║██║        ██║   ██║█████╗   ╚████╔╝                                             ║\n";
    cout << "║                                                    ╚════██║   ██║   ██╔═ ██╝██║   ██║██║  ██╗   ██║   ██║██╔══╝    ╚██╔╝                                              ║\n";
    cout << "║                                                    ███████╗   ██║   ██║  ██╗╚██████╔╝╚██████║   ██║   ██║██║        ██║                                               ║\n";
    cout << "║                                                    ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝╝   ╚═╝   ╚═╝╚═╝        ╚═╝                                               ║\n";
    cout << "x═══════════════════════════════════════════════════════════════════════════PATTERN GENERATOR═══════════════════════════════════════════════════════════════════════════x\n";
    cout << "║                                                                                                                                                                       ║\n";
    cout << "                                                [ LEVEL: "<< level << " ]                             " <<"[ PATTERN: "<< patternName << " ]                               \n";
    cout << "║                                                                                                                                                                       ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
 

}

bool patternOptionsMenu(const vector<string>& patternLines, const string& patternName, const string& level) {
    const string option1 = "Export to text file";
    const string option2 = "Return";
    int selected = 0;

    while (true) {
        system("cls");
        patternHeader(patternName, level);

        cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";

        for (const string& line : patternLines) {
            cout << line << endl;
        }

        cout << "\n\n======================================================================================================================================================================\n\n";
       

        // Options Row
        cout << "\t\t\t\t";

        if (selected == 0) setConsoleColor(240); // Highlight option 1 (black bg, white text)
        cout << "[ " << option1 << " ]";
        setConsoleColor(7); // Reset color

        cout << "    ";

        if (selected == 1) setConsoleColor(240); // Highlight option 2
        cout << "[ " << option2 << " ]";
        setConsoleColor(7);
         cout << "\n                                                                                                                   (←)/(→)=Move           ENTER=Select";
        cout << "\n═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n\n";

        int ch = _getch();

        if (ch == 224) {
            int arrow = _getch();
            if (arrow == 75) selected = max(0, selected - 1);      // Left
            else if (arrow == 77) selected = min(1, selected + 1); // Right
        }
        else if (ch == 13) {
            return selected == 0;
        }
    }
}
// Moves the cursor to (x, y) in the console
void moveCursorTo(int x, int y) {
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Clears only the area where the bar chart is drawn
void clearBarChartArea(int startLine, int height) {
    for (int i = 0; i < height; ++i) {
        moveCursorTo(0, startLine + i);
        cout << string(150, ' '); // Adjust width as needed
    }
    moveCursorTo(0, startLine);
}
void printBarChart(const vector<int>& data, int highlight1 = -1, int highlight2 = -1, int startLine = 26) {
    clearBarChartArea(startLine, data.size());

    for (int i = 0; i < data.size(); ++i) {
        moveCursorTo(0, startLine + i);

        if (i == highlight1 || i == highlight2)
            setConsoleColor(6); 
        else
            setConsoleColor(7); 

        cout << "\t\t"<<setw(2) << data[i] << " | " << string(data[i],'#') << '\n';
    }
    setConsoleColor(7);
}
// Dataset Options
vector<string> getAvailableDatasets(const string& subFolderName) {
   vector<string> datasets;
    string folderPath = "datasets/" + subFolderName;

    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            datasets.push_back(entry.path().filename().string());
        }
    }

    return datasets;
}
string promptDatasetFile(const string& foldername) {
    vector<string> datasets = getAvailableDatasets(foldername);

    if(datasets.empty()){
        cout << "[!] No datasets found in the folder.\n";
        return "";
    }
    int choice = showMenuDataset("Choose a dataset to use:", datasets);
    return "datasets/" + foldername + "/" + datasets[choice];
}
// ==== User Base Class ====
void User::setUsername(const std::string& name) {
    username = name;
}

string User::getUsername() const {
    return username;
}
// ==== Guest Implementation ====
void Guest::dashboard() {
    system("cls");
    int choice = 0;
    

        vector<string> options = {
            "[1] Visualize Algorithm",
            "[2] Visualize Data Structure",
            "[3] Patterns Generator",
            "[4] Logout"
        };
        
        choice = showMenuVisualize("Visualizer Menu:", options);


        system("cls");
        switch (choice) {
            case 0: visualizeAlgorithm(); break;
            case 1: visualizeDataStructure(); break;
            case 2: patternGenerator(); break;
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
           if (algChoice == 5){
            cout << "========================================================================================================================================================================\n";
            cout << "\n\t\tReturning to Main Menu...\n";
            _getch();
            dashboard();
            return;
        }

        vector<string> dataOptions = {
            "[1] Predefined Data",
            "[2] Custom Input",
            "[3] Return"
        };
        int dataChoice = showMenuDataset("Choose data option: ", dataOptions);

        if (dataChoice == 2) visualizeAlgorithm(); 
        
        vector<int> data;
        if (dataChoice == 0) {
            string filename = promptDatasetFile("algorithms");
            data = loadDataFromFile(filename);
        } else if (dataChoice == 1) {
            data = getUserInputData(false);
        }

        bool manualMode = (showMenuDataset("Choose Step Mode:", {"[1] Manual", "[2] Automatic"}) == 0);

        switch (algChoice) {
            case 0: bubbleSort(data, true, manualMode); break;
            case 1: selectionSort(data, true, manualMode); break;
            case 2: insertionSort(data, true, manualMode); break;
            case 3: quickSort(data, 0,  data.size() - 1, true, manualMode); break;
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
        int structChoice = showMenuDSA("Choose Data Structure: ", structOptions);
        if (structChoice == 3){
            cout << "========================================================================================================================================================================\n";
            cout << "\n\t\tReturning to Main Menu...\n";
            _getch();
            dashboard();
            return;
        }

        vector<string> dataOptions = {
            "[1] Predefined Data",
            "[2] Custom Input",
            "[3] Return"
        };
        int dataChoice = showMenuDataset("Use: ", dataOptions);
        if (dataChoice == 2) visualizeDataStructure(); 

        vector<int> data;
        if (dataChoice == 0) {
            string filename = promptDatasetFile("data-structure");
            data = loadDataFromFile(filename);
        } else if (dataChoice == 1) {
            data = getUserInputData(true);
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
            default:
                std::cout << "Invalid Data Structure Selected\n";
        }
        cout << "========================================================================================================================================================================\n";
        std::cout << "\n\t\tPress any key to continue...\n";
        _getch();
    }
}
void Guest::patternGenerator(){
        vector<string> patternDifficultyOptions = {
        "[1] Basic",
        "[2] Intermediate",
        "[3] Complex",
        "[4] Return"
    };

    int difficultyOption = patternDifficultyDashboard(patternDifficultyOptions);

    switch(difficultyOption){
        case 0: basicPatterns(); break;
        case 1: intermediatePatterns();break;
        case 2: complexPatterns();break;
        case 3: dashboard(); break;
    }
}
// ==== Admin Implementation ====
void Admin::dashboard() {
    system("cls");
    std::cout << "\nWelcome Admin, " << username << "!" << std::endl;
    vector<string> adminOptions = {
        "[1] View Export Logs",
        "[2] Manage Datasets",
        "[3] Logout",
    };

    int choice = showMenuVisualize("Admin Dashboard", adminOptions);

    switch (choice) {
        case 0: viewExportedLogs(); break;
        case 1: manageDatasets(); break;
        case 2: return;
    }
}

void Admin::manageDatasets() {
    system("cls");
    vector<string> datasetOptions = {
        "[1] Add Dataset",
        "[2] Remove Dataset",
        "[3] View All Dataset",
        "[4] Return"
    };

    int choice = showMenuManageDataset( datasetOptions);

    switch(choice){
        case 0: addNewDataset(); break;
        case 1: removeDataset(); break;
        case 2: viewAllDatasets(); break;
        case 3: dashboard(); return;
    }
    
}

//==== ADMIN FUNCTIONS ====
void Admin::viewExportedLogs() {
    ifstream logFile("logs.txt");
    if (!logFile) {
        cerr << "[!] Failed to open log file.\n";
        return;
    }

    string line;
    vector<LogEntry> logs;

    while (getline(logFile, line)) {
        stringstream ss(line);
        string timestamp, username, action;

        getline(ss, timestamp, '|');
        getline(ss, username, '|');
        getline(ss, action);

        logs.push_back({ timestamp, username, action });
    }

    logFile.close();

    // Display as table
    cout << "\n\n═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
    cout << left << setw(25) << "Timestamp"
         << setw(15) << "Username"
         << "Action\n";
    cout << string(TERMINAL_WIDTH, '-') << "\n";

    for (const auto& log : logs) {
        cout << left << setw(25) << log.timestamp
             << setw(15) << log.username
             << log.action << "\n";
    }

    cout << string(TERMINAL_WIDTH, '-') << "\n";
    system("pause");
}

void Admin::addNewDataset() {
    system("cls");
    cout << "+-------------------------------------------------+\n";
    cout << "|               Add New Dataset                  |\n";
    cout << "+-------------------------------------------------+\n\n";

    vector<string> categories = {"algorithms", "data-structure"};
    int choice = showMenuDataset("Choose category for the new dataset:", categories);
    string category = categories[choice];

    string datasetName;
    cout << "═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
    cout << "Enter new dataset name (without extension): ";
    cin >> datasetName;

    string fullPath = "datasets/" + category + "/" + datasetName + ".txt";

    if (fs::exists(fullPath)) {
        cout << "\n[!] Dataset already exists.\n";
    } else {
        ofstream file(fullPath);
        if (!file) {
            cout << "\n[!] Failed to create dataset.\n";
        } else {
            cout << "\n[NOTE]: Enter only positive integers. Type 'END' to finish.\n";
            cout << "Input value:\n\n";
            cin.ignore();
            string line;
            while (true) {
                cout << "  > ";
                getline(cin, line);
                if (line == "END") break;

                istringstream iss(line);
                string token;
                bool invalid = false;

                while (iss >> token) {
                    try {
                        int num = stoi(token);
                        if (num < 0) {
                            invalid = true;
                            break;
                        }
                    } catch (...) {
                        invalid = true;
                        break;
                    }
                }

                if (invalid) {
                    cout << "  [!] Invalid input. Please enter only positive integers.\n";
                } else {
                    file << line << '\n';
                }
            }

            file.close();
            cout << "\n[+] Dataset '" << datasetName << "' created in '" << category << "' folder.\n";
        }
    }

    cout << "\n+-------------------------------------------------+\n";
    cout << "Press any key to return...\n";
    _getch();
    manageDatasets();
}

void Admin::removeDataset() {
    system("cls");
    cout << "+-------------------------------------------------+\n";
    cout << "|               Remove Dataset                   |\n";
    cout << "+-------------------------------------------------+\n\n";

    vector<string> categories = {"algorithms", "data-structure"};
    int choice = showMenuDataset("Choose category to remove a dataset from:", categories);
    string category = categories[choice];

    vector<string> datasets = getAvailableDatasets(category);

    if (datasets.empty()) {
        cout << "\n[!] No datasets available in '" << category << "' folder.\n";
    } else {
        int datasetChoice = showMenuDataset("Select a dataset to delete:", datasets);
        string selected = datasets[datasetChoice];
        string path = "datasets/" + category + "/" + selected;

        char confirm;
        cout << "═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
        cout << "\nAre you sure you want to delete '" << selected << "'? (y/n): ";
        cin >> confirm;

        if (tolower(confirm) == 'y') {
            if (fs::remove(path)) {
                cout << "\n[+] Dataset deleted successfully.\n";
            } else {
                cout << "\n[!] Failed to delete dataset.\n";
            }
        } else {
            cout << "\n[-] Deletion cancelled.\n";
        }
    }

    cout << "\n+-------------------------------------------------+\n";
    cout << "Press any key to return...\n";
    _getch();
    manageDatasets();
}

void Admin::viewAllDatasets() {
    system("cls");
    vector<string> categories = {"algorithms", "data-structure"};
    bool hasAny = false;

    cout << "+-------------------------------------------------------------+\n";
    cout << "|                   All Available Datasets                    |\n";
    cout << "+----------------------+--------------------------------------+\n";
    cout << "| CATEGORY             | DATASET NAME                         |\n";
    cout << "+----------------------+--------------------------------------+\n";

    for (const string& category : categories) {
        vector<string> datasets = getAvailableDatasets(category);
        if (!datasets.empty()) {
            hasAny = true;
            for (const string& dataset : datasets) {
                cout << "| " << left << setw(20) << category
                     << " | " << left << setw(36) << dataset << " |\n";
            }
        }
    }

    if (!hasAny) {
        cout << "| " << left << setw(58) << "[!] No datasets found in both folders." << "|\n";
    }

    cout << "+-------------------------------------------------------------+\n";
    cout << "Press any key to return...\n";
    _getch();
    manageDatasets();
}

//Helper Functions
bool Admin::authenticate(std::string& username) {
    const string validUsername = "admin";
    const string validPassword = "123";

    adminHeader();
    cout << "\n\t\t\t\t\t >>> Username: ";
    cin >> username;

    cout << "\t\t\t\t\t >>> Password: ";
    string password;
    char ch;

    while ((ch = _getch()) != 13) { // 13 is Enter key
        if (ch == 8 && !password.empty()) { // Handle backspace
            password.pop_back();
            cout << "\b \b";
        } else if (isprint(ch)) {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << "\n";

    return (username == validUsername && password == validPassword);
}
void exportLog(const std::string& username, const std::string& action) {
     ofstream logFile("logs.txt", ios::app);
    if (!logFile) {
        cerr << "[!] Failed to open log file.\n";
        return;
    }

    // Get current time
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt)-1] = '\0'; // remove newline

    logFile << dt << "|" << username << "|" << action << "\n";
    logFile.close();
};

// ==== Helper Functions ====
//Algorithms
void drawStack(const vector<int>& stackVec, bool showTopLabel = true){
    system("cls");
    dataStructHeader("STACK", "A Stack is a linear data structure that holds a linear, ordered sequence of elements. It is an abstract data type. A Stack works on the LIFO process (Last In First Out), i.e., the element that was inserted last will be removed first.");
    cout << "\t\t --- Stack Visualization (Top to Bottom) ---\n\n";

    if(stackVec.empty()){
        cout << "\t\t[Empty Stack]\n";
        return;
    }

    for(int i = stackVec.size() - 1; i >= 0; --i){
        //Stack top
        cout << "\t\t\t+--------+\n";
        cout << "\t\t\t|   " << stackVec[i];
        //Spacing
        if(stackVec[i] < 10) cout << "    ";
        else if(stackVec[i] < 100 ) cout << "   ";
        else cout << " ";
        //right border
        cout << "|";

        if(i == stackVec.size() - 1 && showTopLabel)
            //Sign
            cout << "  <-- Top";
        //Stack bottom
        cout << "\n\t\t\t+--------+\n";
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
    const string desc = "Merge Sort divides the list into halves, then iterates through the new halves, continually dividing them down further to their smaller parts.";
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
            system("cls");
            algorithmHeader("MERGE SORT", desc);
            setConsoleColor(11); 
            printBarChart(data, left, right); 
            setConsoleColor(14); 
            std::cout << "Merging at index: " << k << std::endl;
            setConsoleColor(7); // Reset
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
         if (showSteps) {
            system("cls");
            algorithmHeader("MERGE SORT", desc);
            printBarChart(data, left, right);
            if (manualSteps) _getch(); else Sleep(500);
        }
    }
    while (j < n2) {
        data[k] = rightArr[j];
        ++j;
        ++k;
        if (showSteps) {
            system("cls");
            algorithmHeader("MERGE SORT", desc);
            printBarChart(data, left, right);
            if (manualSteps) _getch(); else Sleep(500);
        }
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
    dataStructHeader("QUEUE", "A queue in data structures is a linear collection of elements that follows the 'First-In, First-Out' (FIFO) principle. This means elements are added to the rear (or tail) of the queue and removed from the front (or head). Think of it like a line at a store, where the first person in line is the first to be served. ");
    cout << "\n\n\t\t--- Queue Visualization (Front to Rear) ---\n\n";
    
    if (queueVec.empty()) {
        cout << "\t\t[Empty Queue]\n";
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
// ====PATTERN EXPORTER CLASS====
bool PatternExporter::exportPatternToFile(const std::vector<std::string>& lines, const User* user, const string& patternName, const string& level) {
    const string TEMPLATE = R"(╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
                                                                       {{PATTERN_NAME}} PATTERN                                                                                                           
╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
        User: {{USERNAME}}
        Difficulty Level: {{LEVEL}}
        Exported on: {{DATE}}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

{{PATTERN_BODY}}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                       © 2025 Structify. All rights reserved.
=========================================================================================================================================================================
)";
    //For joining the pattern lines
    ostringstream bodyStream;
    for (const string& line : lines)
        bodyStream << line << "\n";

    string patternBody = bodyStream.str();

    //For timestamps
    time_t now = time(0);
    tm* localtm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtm);
    string timestamp(buffer);

    //Replacing placeholders to values from parameter
    string content = TEMPLATE;
    content = regex_replace(content, regex("\\{\\{PATTERN_NAME\\}\\}"), patternName);
    content = regex_replace(content, regex("\\{\\{USERNAME\\}\\}"), user->getUsername());
    content = regex_replace(content, regex("\\{\\{LEVEL\\}\\}"), level);
    content = regex_replace(content, regex("\\{\\{DATE\\}\\}"), timestamp);
    content = regex_replace(content, regex("\\{\\{PATTERN_BODY\\}\\}"), patternBody);

    // Create unique filename
    string code = generateRandomCode(6);
    string safePatternName = patternName;
    replace(safePatternName.begin(), safePatternName.end(), ' ', '_');
    string filename = user->getUsername() + "_" + safePatternName + "_" + code + ".txt";

    ofstream outFile(filename);
    if (!outFile.is_open()) return false;

    outFile << content;
    outFile.close();
     // Automatically log the export
    if (user)
    exportLog(user->getUsername(), "Exported pattern '" + patternName + "' (Level: " + level + ") to file: " + filename);


    cout << "\n✅ Pattern successfully exported to: " << filename << "\n";
    return true;
}
std::string PatternExporter::generateRandomCode(int length) {
    static const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        static std::mt19937 rng(static_cast<unsigned>(time(nullptr)));
        static std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);

        std::string result;
        for (int i = 0; i < length; ++i)
            result += charset[dist(rng)];

        return result;
}

//Patterns Generator
int getPatternHeight(){
    int n;
    while (true) {
        cout << "\n\n\t\t\t\t>>> Input desired pattern height: ";
        cin >> n;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t\t\t\t[!] Invalid input. Please enter a valid number.";
            
        } else if (n < 0) {
            cout << "\t\t\t\t[!] Pattern height must not be negative.";
        } else {
            break; 
        }
    }

    return n;

}

char getPatternSymbol(){
    char symbol;
    string input;

    do {
        cout << "\t\t\t\t>>> Input desired symbol: ";
        cin >> input;

        if (input.length() != 1) {
            cout << "\t\t\t\t[!] Please enter a single character only.\n";
        }
    } while (input.length() != 1);

    symbol = input[0];
    return symbol;
}
//Solid Square, Hollow Square, Right Angled Triangle (Left Aligned), Inverted Right Triangle, Right Angled Triangle (Right Aligned)
void Guest::basicPatterns(){
    const string& level = "BASIC";
    vector<string> basicPatternsOption = {
        "[1] Solid Square",
        "[2] Hollow Square",
        "[3] Left-Padded Right Angled Triangle",
        "[4] Right Angled Triangle",
        "[5] Inverted Right Triangle",
        "[6] Return",
    };

    int choice = patternDifficultyDashboard(basicPatternsOption);

    switch(choice){
        case 0: solidSquare(level, username, *this); break;
        case 1: hollowSquare(level, username, *this); break;
        case 2: rightAngleLeftAlignedTri(level, username, *this); break;
        case 3: rightAngleRightAlignedTri(level, username, *this); break;
        case 4: invertAngleTri(level, username, *this); break;
        case 5: patternGenerator(); return;
    }
}
// Inverted Star Pyramid, Number Pyramid, Floyd's Triangle, Pascal's Triangle, Diamond Pattern
void Guest::intermediatePatterns(){
    const string& level = "INTERMEDIATE";
    vector<string> basicPatternsOption = {
        "[1] Inverted Pyramid", //WITH SYMBOL
        "[2] Number Pyramid",   //NON SYMBOL
        "[3] Floyd's Triangle", //NON SYMBOL
        "[4] Pascal's Triangle", //NON SYMBOL
        "[5] Diamond Pattern",   //WITH SYMBOL
        "[6] Return",
    };

    int choice = patternDifficultyDashboard(basicPatternsOption);

    switch(choice){
        case 0: invertPyramid(level, username, *this); break;
        case 1: numPyramid(level, username, *this); break;
        case 2: floydTri(level, username, *this); break;
        case 3: pascalTri(level, username, *this); break;
        case 4: diamondPattern(level, username, *this); break;
        case 5: patternGenerator(); return;
    }
}
//Palindromic Number Triangle, Hourglass Pattern, Multiplication Table Grid, Heart Pattern, Box with Diagonals
void Guest::complexPatterns(){
    const string& level = "COMPLEX";
    vector<string> basicPatternsOption = {
        "[1] Palindromic Number Triangle", //NON SYMBOL
        "[2] Hourglass Pattern",   //WITH SYMBOL
        "[3] Multiplication Table Grid", //NON SYMBOL
        "[4] Heart Pattern", //WITH SYMBOL
        "[5] Box with Diagonals",   //WITH SYMBOL
        "[6] Return",
    };

    int choice = patternDifficultyDashboard(basicPatternsOption);

    switch(choice){
        case 0: palindromicNumTri(level, username, *this); break;
        case 1: hourglassPattern(level, username, *this); break;
        case 2: multiplicationGrid(level, username, *this); break;
        case 3: heartPattern(level, username, *this); break;
        case 4: boxWithDiagonals(level, username, *this); break;
        case 5: patternGenerator(); return;
    }

}


// ==== Utilities Implementation ====
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
    system("cls");
    algorithmHeader("BUBBLE SORT", "Bubble sort is a simple sorting algorithm that works by repeatedly stepping through the list, comparing adjacent elements, and swapping them if they are in the wrong order. It's called 'bubble sort' because smaller elements 'bubble' to the top of the list as it progresses. ");
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        
        for(int j = 0; j < n - i - 1; ++j){
            if(showSteps){
                printBarChart(data, j, j+1);
                cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                cout << "\t\t\n >>> Comparing " << data[j] << " and " << data[j + 1] << "\n";
                
                if(manualSteps){
                    cout << "========================================================================================================================================================================\n\n";
                    _getch();
                }else{
                    Sleep(800);
                }
            }
            if(data[j] > data [j + 1]){
                swap(data[j], data[j + 1]);
                swapped = true;

                if(showSteps){
                    printBarChart(data, j, j+1);
                    setConsoleColor(4);
                    cout << "\n\t\tSwapped\n";
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
   
    cout << "\n\n\t\tArray is now sorted!\n";

}

void selectionSort(std::vector<int>& data, bool showSteps, bool manualSteps) {
    system("cls");
    algorithmHeader("SELECTION SORT", "Selection sort is a simple comparison-based sorting algorithm that divides the input list into a sorted part at the beginning and an unsorted part at the end.");
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
                cout << "========================================================================================================================================================================\n\n";
                _getch();
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
    system("cls");
    algorithmHeader("INSERTION SORT", "Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time by comparisons. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.");
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
    system("cls");
    algorithmHeader("QUICK SORT", "Quicksort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.");
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
    printBarChart(data);
}

void mergeSort(vector<int>& data, bool showSteps, bool manualSteps) {
    system("cls");
    algorithmHeader("MERGE SORT", "Merge Sort divides the list into halves, then iterates through the new halves, continually dividing them down further to their smaller parts.");
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
        cout << "\n\n\t\tPress any key to enqueue " << data[i] << "...\n";
        Sleep(500);
        queueVec.push_back(data[i]);
        drawQueue(queueVec);
    }

    cout << "\n\t\tAll elements enqueued. Press any key to begin dequeuing...\n";
    _getch();

    // Dequeue phase
    while (!queueVec.empty()) {
        drawQueue(queueVec);
        cout << "\n\n\t\tPress any key to dequeue front element (" << queueVec.front() << ")...\n";
        Sleep(500);
        queueVec.erase(queueVec.begin()); 
    }

    drawQueue(queueVec);
    cout << "\n\t\tQueue is now emptied.\n";
}

void visualizeStack(const vector<int>& data) {
    vector<int> q;

    cout << "\n\t\t --- Stack Visualization ---\n";
     for (size_t i = 0; i < data.size(); ++i) {
        cout << "\t\tPress any key to push " << data[i] << "...\n";
        Sleep(500);
        q.push_back(data[i]);
        drawStack(q);
    }

    cout << "\n\t\tAll elements pushed. Press any key to begin popping...\n";
    _getch();

    // Pop phase with animation
    while (!q.empty()) {
        drawStack(q);
        cout << "\n\t\tPress any key to pop top element (" << q.back() << ")...\n";
        Sleep(500);
        q.pop_back();
    }

    // Final state
    drawStack(q);
    cout << "\n\t\tStack is now emptied.\n";
}
void visualizeLinkedList(const vector<int>& data){
    system("cls");
    dataStructHeader("LINKED LIST", "A linked list is a fundamental data structure that stores a sequence of elements, where each element (called a node) contains data and a pointer (or reference) to the next node in the sequence.");
    cout << "\n\t\t--- Linked List Visualization\n";
    
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
   
    cout << "\n\t\t Traversing Linked List: \n";
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
//BASIC PATTERNS
void solidSquare(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    //Initial screen
    system("cls");
    patternHeader("SOLID SQUARE", level);
    // Get pattern input first
    int height = getPatternHeight();
    char symbol = getPatternSymbol();
    int patternWidth = height;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth) / 2);

    // Generate the pattern once and store in a vector
    vector<string> patternLines;
    //Pattern logic
    for (int i = 0; i < height; i++) {
        patternLines.push_back(string(leftPadding, ' ') + string(patternWidth, symbol));
    }

    // Loop to display and ask
    while (true) {
        system("cls");
        patternHeader("SOLID SQUARE", level);
        cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, "SOLID SQUARE", level);
        break;
    }

    if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        ofstream outFile("pattern.txt");
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, "SOLID Square", level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        }else{
            cout << "\nFailed export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
        
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.basicPatterns();
}
void hollowSquare(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    system("cls");
    patternHeader("HOLLOW SQUARE", level);

    //Get pattern input
    int height = getPatternHeight();
    int width = height;
    char symbol = getPatternSymbol();

    //For aligning center of pattern
    int patternWidth = height;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth) / 2);

    //Storing of pattern output for each line
    vector<string> patternLines;
    //Pattern logic
    for(int i = 0; i < height; ++i){
        string line = string(leftPadding, ' ');
        for(int j = 0; j < width; ++j){
            if(i == 0 || i == height - 1 || j == 0 || j == width - 1){
                //Print the symbol if iteration is equals to the square's border
                line += symbol;
            }else{
                //If content inside print space
                line += " ";
            }
        }
        patternLines.push_back(line);
    }
    
    while(true){
        system("cls");
        patternHeader("HOLLOW SQUARE", level);
         cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, "HOLLOW SQUARE", level);
        break;
    }

      if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, "HOLLOW SQUARE", level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
       
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.basicPatterns();
}
void rightAngleLeftAlignedTri(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    //Initial Screen
    system("cls");
    patternHeader("LEFT-PADDED RIGHT ANGLED TRIANGLE", level);

    //Get pattern input 
    int height = getPatternHeight();
    char symbol = getPatternSymbol();

    //For aligning center of pattern
    int patternWidth = height;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth) / 2);

    //Storing of pattern output for each line
    vector<string> patternLines;
    //Pattern logic
    for(int i = 0; i < height; ++i){
        string line = string(leftPadding, ' ');
        for(int j = 0; j < i; ++j){
            line += symbol;
        }
        patternLines.push_back(line);
    }

    while(true){
        system("cls");
        patternHeader("LEFT-PADDED RIGHT ANGLED TRIANGLE", level);
         cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, "LEFT-PADDED RIGHT ANGLED TRIANGLE", level);
        break;
    }

      if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, "LEFT-PADDED RIGHT ANGLED TRIANGLE", level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
        
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.basicPatterns();
}
void rightAngleRightAlignedTri(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    //Initial Screen
    system("cls");
    patternHeader("RIGHT ANGLED TRIANGLE", level);

    //Get pattern input 
    int height = getPatternHeight();
    char symbol = getPatternSymbol();

    //For aligning center of pattern
    int patternWidth = height;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth) / 2);

    //Storing of pattern output for each line
    vector<string> patternLines;
    //Pattern logic
    for(int i = 0; i < height; ++i){
        string line = string(leftPadding, ' ');
        for(int s = 0; s < height - i; ++s){
            line += " ";
        }
        for(int j = 0; j < i; ++j){
            line += symbol;
        }
        
        patternLines.push_back(line);
    }

    while(true){
        system("cls");
        patternHeader("RIGHT ANGLED TRIANGLE", level);
         cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, "RIGHT ANGLED TRIANGLE", level);
        break;
    }

      if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, "RIGHT ANGLED TRIANGLE", level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
        
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.basicPatterns();
}
void invertAngleTri(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    //Initial Screen
    system("cls");
    patternHeader("INVERTED RIGHT TRIANGLE", level);

    //Get pattern input 
    int height = getPatternHeight();
    char symbol = getPatternSymbol();

    //For aligning center of pattern
    int patternWidth = height;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth) / 2);

    //Storing of pattern output for each line
    vector<string> patternLines;
    //Pattern logic
    for(int i = 0; i < height; i++){
        string line = string(leftPadding, ' ');
        for(int j = 0; j < height-i; j++){
            line += symbol;
        }
        
        patternLines.push_back(line);
    }

    while(true){
        system("cls");
        patternHeader("INVERTED RIGHT TRIANGLE", level);
         cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, "INVERTED RIGHT TRIANGLE", level);
        break;
    }

      if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, "INVERTED RIGHT TRIANGLE", level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.basicPatterns();
}
//INTERMEDIATE PATTERNS
void invertPyramid(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    string pattern = "INVERTED PYRAMID";
    //Initial Screen
    system("cls");
    patternHeader(pattern, level);

    //Get pattern input 
    int height = getPatternHeight();
    char symbol = getPatternSymbol();

    //For aligning center of pattern
    int patternWidth = height;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth * 2) / 2);

    //Storing of pattern output for each line
    vector<string> patternLines;
    //Pattern logic
    for(int i = 0; i < height; i++){
        string line = string(leftPadding + i, ' ');
        int stars = 2 * (height - i) - 1; 
        line+= string(stars, symbol);
        patternLines.push_back(line);
    }

    while(true){
        system("cls");
        patternHeader(pattern, level);
         cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, pattern, level);
        break;
    }

      if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, pattern, level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
        
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.intermediatePatterns();
}

void numPyramid(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    string pattern = "NUMBER PYRAMID";
    //Initial Screen
    system("cls");
    patternHeader(pattern, level);

    //Get pattern input 
    int height = getPatternHeight();

    //For aligning center of pattern
    int patternWidth = 2 * height - 1;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth) / 2);

    //Storing of pattern output for each line
    vector<string> patternLines;
    //Pattern logic
    if(height > 10){
        cout << "\n\n-------------------------------------------------------------------WARNING: Heights above 10 will cause visual asymmetry due to multi-digit row numbers being reduced to a single digit.-----------------------------------------------------------------------\n\n";
    }
    for (int i = 1; i <= height; i++) {
        string line = string(leftPadding + (height - i), ' '); // Center alignment
        string numStr = to_string(i); 

        for (int j = 1; j <= (2 * i - 1); j++) {
            line += numStr;
        }

        patternLines.push_back(line);
    }

    while(true){
        system("cls");
        patternHeader(pattern, level);
         cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, pattern, level);
        break;
    }

      if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, pattern, level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
        
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.intermediatePatterns();
}

void floydTri(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    string pattern = "FLOYD'S TRIANGLE";
    //Initial Screen
    system("cls");
    patternHeader(pattern, level);

    //Get pattern input 
    int height = getPatternHeight();

    //For aligning center of pattern
    int patternWidth = height;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth * 2) / 2);

    //Storing of pattern output for each line
    vector<string> patternLines;
    //Pattern logic
    int num = 0; //element to print tracker
    for(int i = 0; i < height; i++){
        string line = string(leftPadding, ' ');
        for(int j = 0; j <= i; j++){
            num++;
            line += to_string(num) + " ";
        }
        patternLines.push_back(line);
    }

    while(true){
        system("cls");
        patternHeader(pattern, level);
         cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, pattern, level);
        break;
    }

      if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, pattern, level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
       
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.intermediatePatterns();
}

void pascalTri(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    string pattern = "PASCAL'S TRIANGLE";
    //Initial Screen
    system("cls");
    patternHeader(pattern, level);

    //Get pattern input 
    int height = getPatternHeight();

    // Prepare triangle structure and output lines
    vector<vector<int>> triangle(height);
    vector<string> patternLines;

    //Pattern logic
    for(int i = 0; i < height; ++i){
        triangle[i].resize(i + 1); //Each row would have the number of columns number of current row plus because it start i starts with 0
        triangle[i][0] = triangle[i][i] = 1;
        for(int j = 1; j < i; ++j){
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i-1][j];
        }
    }
    //Conversion to centered strings for UI
    const int fieldWidth = 6;

    for (int i = 0; i < height; ++i) {
        stringstream lineStream;

        for (int num : triangle[i]) {
            lineStream << setw(fieldWidth) << num;
        }

        string line = lineStream.str();
        int padding = max(0, ((TERMINAL_WIDTH - static_cast<int>(line.length())) / 2));
        string centeredLine = string(padding - 3, ' ') + line;

        patternLines.push_back(centeredLine);
    }

    //Menu loop
    while(true){
        system("cls");
        patternHeader(pattern, level);
         cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, pattern, level);
        break;
    }
        //Export Logic
      if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, pattern, level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.intermediatePatterns();
}
void diamondPattern(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    string pattern = "DIAMOND PATTERN";
    //Initial Screen
    system("cls");
    patternHeader(pattern, level);

    //Get pattern input 
    int height;
    //Height must be odd for perfect symmetry eme2
    while (true) {
        cout << "\n\n\t\t\t\t>>> Input desired pattern height (odd number): ";
        cin >> height;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t\t\t\t[!] Invalid input. Please enter a valid number.";
            
        } else if (height < 0) {
            cout << "\t\t\t\t[!] Pattern height must not be negative.";
        } else if (height % 2 == 0) {
            cout << "\t\t\t\t[!] Pattern height must be odd.";
        }else {
            break; 
        }
    }
    char symbol = getPatternSymbol();

    //For aligning center of pattern
    int patternWidth = height;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth) / 2);

    //Storing of pattern output for each line
    vector<string> patternLines;
    //Pattern logic
   for (int i = 1; i <= 2 * height - 1; ++i) {
        int totalColsInRow = i <= height ? i : 2 * height - i; //create a variable for total colums in rows, conditional to track if rows is less than or exceeds the given height 
        int spaces = (TERMINAL_WIDTH - (2 * totalColsInRow - 1)) / 2; //printing spaces

        string line = string(spaces, ' ');
        for (int j = 0; j < 2 * totalColsInRow - 1; ++j) {
            line += symbol;
        }

        patternLines.push_back(line);
    }

    while(true){
        system("cls");
        patternHeader(pattern, level);
         cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, pattern, level);
        break;
    }

      if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, pattern, level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
        
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.intermediatePatterns();
}

//COMPLEX PATTERNS
//Palindromic Number Triangle, Hourglass Pattern, Spiral Pattern, Heart Pattern, Box with Diagonals
void palindromicNumTri(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    string pattern = "PALINDROMIC NUMBER TRIANGLE";
    //Initial Screen
    system("cls");
    patternHeader(pattern, level);

   //Get pattern input 
    int height = getPatternHeight();

    //For aligning center of pattern
    int patternWidth = 2 * height - 2;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth) / 2);

    //Storing of pattern output for each line
    vector<string> patternLines;
    //Pattern logic
    for (int i = 1; i <= height; i++) {
        ostringstream oss;

        // Each number will be 3 characters wide, so leftPadding must consider that
        int totalCharsInLine = (2 * i - 1); 
        int lineWidth = totalCharsInLine * 2;
        int spaces = max(0, (TERMINAL_WIDTH - lineWidth) / 2);
        oss << string(spaces, ' ');

        // Ascending
        for (int j = 1; j <= i; ++j) {
            oss << to_string(j) << " ";
        }

        // Descending
        for (int j = i - 1; j >= 1; --j) {
            oss << to_string(j) << " ";
        }

        

        patternLines.push_back(oss.str());
    }

    while(true){
        system("cls");
        patternHeader(pattern, level);
         cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, pattern, level);
        break;
    }

      if (exportToFile) {
        Guest tempGuest;
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, pattern, level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
        
    }
    cout << "Press any key to continue...\n";
    _getch();
    guest.complexPatterns();
}
void hourglassPattern(const string& level, const string& username, Guest& guest) {
    bool exportToFile;
    string pattern = "HOURGLASS PATTERN";

    // Initial Screen
    system("cls");
    patternHeader(pattern, level);

    // Get pattern input 
    int height = getPatternHeight();
    char symbol = getPatternSymbol();

    // For aligning center of pattern
    int patternWidth = height;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth * 2) / 2);

    // Storing of pattern output for each line
    vector<string> patternLines;

    // Pattern logic
    for (int i = 0; i < 2 * height - 1; ++i) {
        string line;

        int current = (i < height) ? i : (2 * height - 2 - i); // Mirror around middle row
        int spaces = current;
        int stars = height - current;

        line += string(leftPadding + spaces, ' ');
        for (int j = 0; j < stars; ++j) {
            line += symbol;
            if (j < stars - 1) line += ' ';
        }

        patternLines.push_back(line);
    }

    while (true) {
        system("cls");
        patternHeader(pattern, level);
        cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, pattern, level);
        break;
    }

    if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, pattern, level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
    }

    cout << "Press any key to continue...\n";
    _getch();
    guest.complexPatterns();
}

void multiplicationGrid(const string& level, const string& username, Guest& guest) {
    bool exportToFile;
    string pattern = "MULTIPLICATION TABLE GRID";

    // Initial screen
    system("cls");
    patternHeader(pattern, level);

    // Get pattern input 
    int height = getPatternHeight(); 


    // For aligning center of pattern
    int cellWidth = 4; 
    int patternWidth = height * 2 - 1;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth) / 2);

    // Prepare pattern lines
    vector<string> patternLines;

    for (int i = 1; i <= height; i++) {
        string line(leftPadding - height, ' ');
        for (int j = 1; j <= height; j++) {
            line += to_string(i * j);
            int space = cellWidth - to_string(i * j).length();
            line += string(space, ' ');
        }
        patternLines.push_back(line);
    }

    while (true) {
        system("cls");
        patternHeader(pattern, level);
        cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";

        for (const string& line : patternLines) {
            cout << string(leftPadding, ' ') << line << '\n';
        }

        exportToFile = patternOptionsMenu(patternLines, pattern, level);
        break;
    }

    if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, pattern, level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
    }

    cout << "Press any key to continue...\n";
    _getch();
    guest.complexPatterns();
}

void heartPattern(const string& level, const string& username, Guest& guest){
    bool exportToFile;
    string pattern = "HEART PATTERN";

    // Initial screen
    system("cls");
    patternHeader(pattern, level);

    // Get pattern input
    int size;
    while (true) {
        cout << "\n\n\t\t\t\t>>> Input desired pattern size (odd number): ";
        cin >> size;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t\t\t\t[!] Invalid input. Please enter a valid number.";
            
        } else if (size < 0) {
            cout << "\t\t\t\t[!] Pattern height must not be negative.";
        } else if (size % 2 == 0) {
            cout << "\t\t\t\t[!] Pattern height must be odd.";
        }else if (size < 5) {
            cout << "\t\t\t\t[!] Heart pattern size must be more than 5.";
        }
        else {
            break; 
        }
    }
    char symbol = getPatternSymbol();

    int width = size * 2;
    int leftPadding = max(0, (TERMINAL_WIDTH - width) / 2);

    vector<string> patternLines;

    // Top arcs of the heart
    for (int i = size / 2; i <= size; i += 2) {
        string line(leftPadding, ' ');

        for (int j = 1; j < size - i; j += 2)
            line += " ";

        for (int j = 1; j <= i; ++j)
            line += symbol;

        for (int j = 1; j <= size - i; ++j)
            line += " ";

        for (int j = 1; j <= i; ++j)
            line += symbol;

        patternLines.push_back(line);
    }

    // Inverted triangle bottom of the heart
    for (int i = size; i >= 1; --i) {
        string line(leftPadding + size - i, ' ');
        for (int j = 1; j <= (i * 2) - 1; ++j)
            line += symbol;
        patternLines.push_back(line);
    }

    // Display and export
    while (true) {
        system("cls");
        patternHeader(pattern, level);
        cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, pattern, level);
        break;
    }

    if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, pattern, level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
    }

    cout << "Press any key to continue...\n";
    _getch();
    guest.complexPatterns();
}
void boxWithDiagonals(const string& level, const string& username, Guest& guest){
        bool exportToFile;
    string pattern = "BOX WITH DIAGONALS";

    // Initial screen
    system("cls");
    patternHeader(pattern, level);

    // Get pattern input
    int size = getPatternHeight(); // Square size
    char symbol = getPatternSymbol();

    // For centering
    int patternWidth = size;
    int leftPadding = max(0, (TERMINAL_WIDTH - patternWidth * 2) / 2);

    vector<string> patternLines;

    // Pattern logic
    for (int row = 0; row < size; ++row) {
        string line(leftPadding, ' ');
        for (int col = 0; col < size; ++col) {
            if (row == 0 || row == size - 1 || col == 0 || col == size - 1 || row == col || col == size - row - 1) {
                line += symbol;
                line += ' ';
            } else {
                line += "  ";
            }
        }
        patternLines.push_back(line);
    }

    // Display and export options
    while (true) {
        system("cls");
        patternHeader(pattern, level);
        cout << "\n\n-----------------------------------------------------------------------GENERATED PATTERN PREVIEW-----------------------------------------------------------------------\n\n";
        for (const string& line : patternLines) {
            cout << line << endl;
        }

        exportToFile = patternOptionsMenu(patternLines, pattern, level);
        break;
    }

    if (exportToFile) {
        Guest tempGuest;
        tempGuest.setUsername(username);
        if (PatternExporter::exportPatternToFile(patternLines, &tempGuest, pattern, level)) {
            cout << "\nPattern successfully exported to a text file.\n";
        } else {
            cout << "\nFailed to export pattern to file.\n";
        }
    } else {
        cout << "\nReturning without exporting...\n";
    }

    cout << "Press any key to continue...\n";
    _getch();
    guest.complexPatterns();
}

//==== Helper Functions ====
vector<int> getUserInputData(bool isDataStructure = false) {
    vector<int> data;
    int n;
    if (isDataStructure) {
        cout << "\n-----[WARNING]: Data Structure Visualization is limited to 10 elements to avoid negative user experience-----\n";
    }
    else{
        cout << "\n[NOTE]: You can add data in a .txt file inside the (datasets/algorithms/) file path for easier data input.\n";
    }
    cout << "Enter number of elements: ";

    while (!(cin >> n) || n <= 0 || (isDataStructure && n > 10)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "[!] Invalid input. Enter a positive number";
        if (isDataStructure) cout << " up to 10";
        cout << ": ";
    }

    cout << "Enter " << n << " integer" << (n > 1 ? "s" : "") << ": ";
    for (int i = 0; i < n; ++i) {
        int val;
        cout << "\n  > Element [" << i + 1<< "]: ";
        while (!(cin >> val)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "    [!] Invalid input. Please enter an integer: ";
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