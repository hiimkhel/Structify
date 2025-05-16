#ifndef STRUCTIFY_H
#define STRUCTIFY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
//==== Menu UI ====
int showMenu(const string& title, const vector<string>& options);

// ==== Base Class ====
class User {
protected:
    std::string username;
public:
    virtual void dashboard() = 0;
    void setUsername(const std::string& name);
    virtual ~User() {}
};

// ==== Guest Class ====
class Guest : public User {
public:
    void dashboard() override;
    void visualizeAlgorithm();
    void visualizeDataStructure();
    void patternGenerator();
};

// ==== Admin Class ====
class Admin : public User {
public:
    void dashboard() override;
    void viewSystemLogs();
    void manageDatasets();
};

// ==== Utilities ====
void clearScreen();
std::vector<int> loadDataFromFile(const string& filename);
std::vector<int> getUserInputData();
void printVector(const vector<int>& data);

// ==== Algorithms ====
void bubbleSort(vector<int>& data, bool showSteps = true, bool manualSteps = false);
void selectionSort(vector<int>& data, bool showSteps = true, bool manualSteps = false);
void insertionSort(vector<int>& data, bool showSteps = true, bool manualSteps = false);
void quickSort(vector<int>& data,int low, int high, bool showSteps = true, bool manualSteps = false);
void mergeSort(vector<int>& data, bool showSteps = true, bool manualSteps = false);

// ==== Data Structures ====
void visualizeQueue(const vector<int>& data);
void visualizeStack(const vector<int>& data);
void visualizeLinkedList(const vector<int>& data);


// ==== Patterns ====
void solidRectangle();
void hollowRectangle();
void rightAngleRightAlignedTri();
void rightAngleLeftAlignedTri();
void invertAngleTri();
#endif
