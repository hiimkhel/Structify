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
};

// ==== Guest Class ====
class Guest : public User {
public:
    void dashboard() override;
    void visualizeAlgorithm();
    void visualizeDataStructure();
    void recursionVisualizer();
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
std::vector<int> loadDataFromFile(const std::string& filename);
std::vector<int> getUserInputData();
void printVector(const std::vector<int>& data);

// ==== Algorithms ====
void bubbleSort(std::vector<int>& data, bool showSteps = true, bool manualSteps = false);
void selectionSort(std::vector<int>& data, bool showSteps = true);

// ==== Data Structures ====
void visualizeBinaryTree();
void visualizeStack();

// ==== Recursion ====
void visualizeFactorial(int n, int depth = 0);

#endif
