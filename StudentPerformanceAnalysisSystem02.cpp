// Student Performance Analysis System - Part 01

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function Declarations
double generateWeight(int testNumber, int totalTests);
double calculateWeightedScore(vector<int>& studentMarks, int totalTests);
bool decliningTrend(vector<int>& marks, int totalTests);


// 01. Function to generate priority/weight automatically
double generateWeight(int testNumber, int totalTests)
{
    // Linear Priority Algorithm
    return testNumber + 1;
}

// 02. Function to calculate weighted average
double calculateWeightedScore( vector<int>& studentMarks, int totalTests ) 
{
    double weightedSum = 0;
    double totalWeight = 0;

    for(int i = 0; i < totalTests; i++)
    {
        double weight = generateWeight(i, totalTests);

        weightedSum += studentMarks[i] * weight;
        totalWeight += weight;
    }

    return weightedSum / totalWeight;
}

// 03. Function to detect declining trend
bool decliningTrend(vector<int>& marks, int totalTests)
{
    // Need minimum 4 tests for applying this testcase
    if(totalTests < 4)
    {
        return false;
    }

    int recentWindow;

    // Decide window size dynamically
    if(totalTests == 4)
    {
        recentWindow = 2;
    }
    else if(totalTests >= 5 && totalTests <= 8)
    {
        recentWindow = 3;
    }
    else
    {
        recentWindow = 5;
    }

    // Calculate overall average
    double overallSum = 0;

    for(int i = 0; i < totalTests; i++)
    {
        overallSum += marks[i];
    }

    double overallAvg = overallSum / totalTests;

    // Calculate recent average
    double recentSum = 0;

    for(int i = totalTests - recentWindow;
        i < totalTests;
        i++)
    {
        recentSum += marks[i];
    }

    double recentAvg = recentSum / recentWindow;

    // Rule Check
    if(recentAvg < overallAvg - 15)
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

    // 2D Matrix for storing marks
    vector<vector<int>> marks(
        students,
        vector<int>(tests)
    );

    // Input marks
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

    // Final Analysis
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

        cout << "\nWeighted Score: "
             << fixed
             << setprecision(2)
             << finalScore;

        // Risk Detection
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

        // Declining Trend Warning
        if(trendRisk)
        {
            cout << "\nWarning: Declining Performance Trend";
        }

        cout << "\n-------------------------";
    }

    return 0;
}
