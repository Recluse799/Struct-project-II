// StThis program reads data from the file "marathon_data.txt" into an array of Runner structs,
//  calculates the total miles and average miles for each runner, and then outputs the results in a table 
// format. Adjust the NUM_DAYS constant according to the number of days in your data file, and make sure your data
//  file is formatted correctly with each line containing the runner's name followed by the miles run each day.





#include <iostream>

int main()
{
   
}
Immanuel Braxton
//  5//7/24
// Arrays and Structs Project I.cpp : This file contains the data for each runner is stored in a Runner struct,
 which contains the runner's name, an array for the miles run each day, 
// and a variable for the daily average. The functions getData, calTotalAvg, and outputResults are modified to work with this struct
// Function prototypes

////void calculateTotalsAndAverage(const string runners[], const double mil[][NUM_DAYS], int numRunners, int total[], double average[]);
//void outputResults(const string runners[], const int miles[][NUM_DAYS], int numRunners, const int total[], const double average[]);
//// Function prototypes
//Precondition - expects reference to names array and run time for each day, all are empty, has maxium capactiy of rows)
//Post conditon- return actual number of files, and store the data in the arrays in memory);;

* /
include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAXROWS = 50;
const int NUM_DAYS = 8;
const string filename = "marathon_data.txt";

// Define struct to store runner data
struct Runner {
    string name;
    double miles[NUM_DAYS];
    double dailyAvg;
};

// Function prototypes
int getData(Runner runners[], int MaxRows);
void calTotalAvg(Runner runners[], int numRunners);
void outputResults(Runner runners[], int numRunners);

int main() {
    Runner runners[MAXROWS];
    int numRecords = getData(runners, MAXROWS);

    if (numRecords == -1) {
        cout << "Error opening file\n";
        return 1;
    }

    cout << "numRecords = " << numRecords << endl;

    for (int i = 0; i < numRecords; i++) {
        cout << runners[i].name << " ";
        for (int j = 0; j < NUM_DAYS; j++)
            cout << runners[i].miles[j] << " ";
        cout << endl;
    }

    calTotalAvg(runners, numRecords);
    outputResults(runners, numRecords);

    return 0;
}

int getData(Runner runners[], int MaxRows) {
    ifstream inFile(filename.c_str());
    if (!inFile.is_open()) {
        return -1; // Return -1 if file cannot be opened
    }

    int rows = 0;
    while (rows < MaxRows && inFile >> runners[rows].name) {
        for (int i = 0; i < NUM_DAYS; i++) {
            inFile >> runners[rows].miles[i];
        }
        rows++;
    }
    inFile.close();
    return rows;
}

void calTotalAvg(Runner runners[], int numRunners) {
    for (int i = 0; i < numRunners; i++) {
        double sum = 0;
        for (int j = 0; j < NUM_DAYS; j++) {
            sum += runners[i].miles[j];
        }
        runners[i].dailyAvg = sum / (NUM_DAYS - 1);
    }
}

void outputResults(Runner runners[], int numRunners) {
    cout << setw(10) << "Name" << setw(6) << "Mon" << setw(6) << "Tue" << setw(6) << "Wed" << setw(6) << "Thu" << setw(6) << "Fri" << setw(6) << "Sat" << setw(6) << "Sun" << setw(12) << "Daily Avg" << endl;

    for (int i = 0; i < numRunners; ++i) {
        cout << setw(10) << runners[i].name;
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << setw(6) << runners[i].miles[j];
        }
        cout << setw(10) << runners[i].dailyAvg << setw(12) << fixed << setprecision(2) << runners[i].dailyAvg << endl;
    }
}