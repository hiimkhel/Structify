#ifndef STRUCTIFY_H
#define STRUCTIFY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
//==== Menu UI ====
void structifyHeader();
// ==== Base Class ====
class User {
protected:
    std::string username;
public:
    virtual void dashboard() = 0;
    void setUsername(const std::string& name);
    virtual ~User() {}

    std::string getUsername()const;

};

// ==== Guest Class ====
class Guest : public User {
public:
    void dashboard() override;
    void visualizeAlgorithm();
    void visualizeDataStructure();
    void patternGenerator();
    void basicPatterns();
    void intermediatePatterns();
    void complexPatterns();
};

// ==== Admin Class ====
class Admin : public User {
public:
    void dashboard() override; //authentication
    static bool authenticate(std::string& username);
    //CRUD Datasets
    void manageDatasets();
    void viewAllDatasets();
    void addNewDatasets();
    void editNewDatasets();
    void removeNewDatasets();
    void toggleDatasetAvailability();

    //Logs
    void viewExportedLogs();
    void exportLog(const std::string& username, const std::string& action);
    struct LogEntry {
    std::string timestamp;
    std::string username;
    std::string action;
    };
};

// ==== Utilities ====
class PatternExporter {
public:
    static bool exportPatternToFile(const std::vector<std::string>& lines, const User* user, const string& patternName, const string& level);
private:
    static std::string generateRandomCode(int length = 6);
};
std::vector<int> loadDataFromFile(const string& filename);
std::vector<int> getUserInputData(bool isDataStructure);
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
//BASIC PATTERNS
void solidSquare(const string& level, const std::string& username, Guest& guest);
void hollowSquare(const string& level, const std::string& username, Guest& guest);
void rightAngleRightAlignedTri(const string& level, const std::string& username, Guest& guest);
void rightAngleLeftAlignedTri(const string& level, const std::string& username, Guest& guest);
void invertAngleTri(const string& level, const std::string& username, Guest& guest);
//INTERMEDIATE PATTERNS
void invertPyramid(const string& level, const string& username, Guest& guest);
void numPyramid(const string& level, const string& username, Guest& guest);
void floydTri(const string& level, const string& username, Guest& guest);
void pascalTri(const string& level, const string& username, Guest& guest);
void diamondPattern(const string& level, const string& username, Guest& guest);
//COMPLEX PATTERNS
void palindromicNumTri(const string& level, const string& username, Guest& guest);
void hourglassPattern(const string& level, const string& username, Guest& guest);
void multiplicationGrid(const string& level, const string& username, Guest& guest);
void heartPattern(const string& level, const string& username, Guest& guest);
void boxWithDiagonals(const string& level, const string& username, Guest& guest);
#endif
