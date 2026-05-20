// Student Performance Analysis System - Part 03

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function Declarations
double generateWeight(int testNumber, int totalTests);
double calculateWeightedScore(vector<int>& studentMarks, int totalTests);
bool decliningTrend(vector<int>& marks, int totalTests);
bool inconsistentPerformance(vector<int>& marks, int totalTests);


// 01. Function to generate priority/weight automatically
// Using a linear priority logic here so later tests matter more
double generateWeight(int testNumber, int totalTests)
{
    // Linear Priority Algorithm
    return testNumber + 1; // simple linear weight: 1, 2, 3...
}

// 02. Function to calculate weighted average
double calculateWeightedScore( vector<int>& studentMarks, int totalTests ) 
{
    double weightedSum = 0;
    double totalWeight = 0; // need this for the denominator

    for(int i = 0; i < totalTests; i++)
    {
        double weight = generateWeight(i, totalTests);

        weightedSum += studentMarks[i] * weight;
        totalWeight += weight; // keeping track of total weight 
    }

    return weightedSum / totalWeight; // final weighted avg
}

// 03. Function to detect declining trend, Checks if recent performance has dropped compared to overall average
bool decliningTrend(vector<int>& marks, int totalTests)
{
    // Need minimum 4 tests for applying this testcase to make sense
    if(totalTests < 4)
    {
        return false;
    }

    int recentWindow;

    // Decide window size dynamically based on how many tests we took
    if(totalTests == 4)
    {
        recentWindow = 2; // last 2 tests
    }
    else if(totalTests >= 5 && totalTests <= 8)
    {
        recentWindow = 3; // last 3 tests
    }
    else
    {
        recentWindow = 5; // enough data to look at the last 5
    }

    // Calculate overall average first
    double overallSum = 0;

    for(int i = 0; i < totalTests; i++)
    {
        overallSum += marks[i];
    }

    double overallAvg = overallSum / totalTests;

    // Calculate recent average using our dynamic window
    double recentSum = 0;

    for(int i = totalTests - recentWindow;
        i < totalTests;
        i++)
    {
        recentSum += marks[i];
    }

    double recentAvg = recentSum / recentWindow;

    // Rule Check: If recent performance drops by more than 15 marks
    if(recentAvg < overallAvg - 15)
    {
        return true; // Flag for declining trend
    }

    return false;
}

// 04. Function to chech inconsestency 
bool inconsistentPerformance(vector<int>& marks, int totalTests)
{
    int highest = marks[0];
    int lowest = marks[0];

    // Find highest and lowest marks
    for(int i = 1; i < totalTests; i++)
    {
        if(marks[i] > highest)
        {
            highest = marks[i];
        }

        if(marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    int variation = highest - lowest;

    // Rule Check
    if(variation >= 35)
    {
        return true;
    }

    return false;
}


int main()
{
    int students;
    int tests;

    cout << "Enter Number of Students: ";
    cin >> students;

    cout << "Enter Number of Tests: ";
    cin >> tests;

    // 2D Matrix for storing marks (rows = students, cols = tests)
    vector<vector<int>> marks(
        students,
        vector<int>(tests)
    );

    // Input marks loop
    cout << "\n===== ENTER MARKS =====\n";

    for(int i = 0; i < students; i++)
    {
        cout << "\nStudent " << i + 1 << ":\n";

        for(int j = 0; j < tests; j++)
        {
            cout << "Test " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\n\n===== RESULT ANALYSIS =====\n";

    // Final Analysis: crunching the numbers for each student
    for(int i = 0; i < students; i++)
    {
        double finalScore =
            calculateWeightedScore(
                marks[i],
                tests
            );

        bool trendRisk =
            decliningTrend(
                marks[i],
                tests
            );

        cout << "\nStudent " << i + 1;

        // Output formatting to 2 decimal places so it looks clean
        cout << "\nWeighted Score: "
             << fixed
             << setprecision(2)
             << finalScore;

        // Risk Detection based on final weighted score thresholds
        if(finalScore >= 70)
        {
            cout << "\nStatus: PREPARED";
        }
        else if(finalScore >= 55)
        {
            cout << "\nStatus: NEEDS ATTENTION";
        }
        else
        {
            cout << "\nStatus: EXTRA CLASSES REQUIRED";
        }

        // Alert if the student is slacking recently
        if(trendRisk)
        {
            cout << "\nWarning: Declining Performance Trend";
        }

        cout << "\n-------------------------";
    }

    return 0;
}
