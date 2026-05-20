#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to generate priority/weight automatically
double generateWeight(int testNumber, int totalTests)
{
    // Linear Priority Algorithm
    // Later tests get higher importance

    return testNumber + 1;

    /*
        Other possible algorithms:

        return (testNumber + 1) * (testNumber + 1);
        return (double)(testNumber + 1) / totalTests;
    */
}

// Function to calculate weighted average
double calculateWeightedScore(
    vector<int>& studentMarks,
    int totalTests
)
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

int main()
{
    int students;
    int tests;

    cout << "Enter Number of Students: ";
    cin >> students;

    cout << "Enter Number of Tests: ";
    cin >> tests;

    // 2D Matrix
    vector<vector<int>> marks(students, vector<int>(tests));

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
            calculateWeightedScore(marks[i], tests);

        cout << "\nStudent " << i + 1;
        cout << "\nWeighted Score: "
             << fixed << setprecision(2)
             << finalScore;

        // Risk Detection
        if(finalScore >= 70)
        {
            cout << "\nStatus: PREPARED";
        }
        else if(finalScore >= 55 && finalScore < 70)
        {
            cout << "\nStatus: NEEDS ATTENTION";
        }
        else
        {
            cout << "\nStatus: EXTRA CLASSES REQUIRED";
        }

        cout << "\n-------------------------";
    }

    return 0;
}
