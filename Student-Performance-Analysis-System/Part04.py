# Student Performance Analysis System - Part 04

import sys

# Function Declarations (Implicit in Python, but following the structure)

# 01. Function to generate priority/weight automatically
# Using a linear priority logic here so later tests matter more
def generate_weight(test_number, total_tests):
    # Linear Priority Algorithm
    return test_number + 1  # simple linear weight: 1, 2, 3...

# 02. Function to calculate weighted average
def calculate_weighted_score(student_marks, total_tests):
    weighted_sum = 0.0
    total_weight = 0.0  # need this for the denominator

    for i in range(total_tests):
        weight = generate_weight(i, total_tests)

        weighted_sum += student_marks[i] * weight
        total_weight += weight  # keeping track of total weight

    return weighted_sum / total_weight  # final weighted avg

# 03. Function to detect declining trend
# Checks if recent performance has dropped compared to overall average
def declining_trend(marks, total_tests):
    # Need minimum 4 tests for applying this testcase to make sense
    if total_tests < 4:
        return False

    recent_window = 0

    # Decide window size dynamically based on how many tests we took
    if total_tests == 4:
        recent_window = 2  # last 2 tests
    elif total_tests >= 5 and total_tests <= 8:
        recent_window = 3  # last 3 tests
    else:
        recent_window = 5  # enough data to look at the last 5

    # Calculate overall average first
    overall_sum = 0.0

    for i in range(total_tests):
        overall_sum += marks[i]

    overall_avg = overall_sum / total_tests

    # Calculate recent average using our dynamic window
    recent_sum = 0.0

    for i in range(total_tests - recent_window, total_tests):
        recent_sum += marks[i]

    recent_avg = recent_sum / recent_window

    # Rule Check: If recent performance drops by more than 15 marks
    if recent_avg < overall_avg - 15:
        return True  # Flag for declining trend

    return False

# 04. Function to check inconsistency
# Basically seeing if their scores are all over the place
def inconsistent_performance(marks, total_tests):
    # Start by assuming the first test is both highest and lowest
    highest = marks[0]
    lowest = marks[0]

    # Find highest and lowest marks across all tests
    for i in range(1, total_tests):
        if marks[i] > highest:
            highest = marks[i]  # update max

        if marks[i] < lowest:
            lowest = marks[i]  # update min

    variation = highest - lowest  # gap between best and worst day

    # Rule Check: if difference is 35+, they are too volatile
    if variation >= 35:
        return True

    return False

# 05. Function to check for consecutive failures (marks below 40)
# Tracks the longest streak of bombing tests
def consecutive_failures(marks, total_tests):
    current_fails = 0
    max_fails = 0

    for i in range(total_tests):
        if marks[i] < 40:  # 40 is our passing criteria here
            current_fails += 1

            # Update the worst streak if the current one is longer
            if current_fails > max_fails:
                max_fails = current_fails
        else:
            # Reset streak if they manage to pass one
            current_fails = 0

    return max_fails

def main():
    # Input for students and tests
    try:
        students_input = input("Enter Number of Students: ")
        students = int(students_input)

        tests_input = input("Enter Number of Tests: ")
        tests = int(tests_input)
    except ValueError:
        return

    # 2D Matrix for storing marks (rows = students, cols = tests)
    # Initializing with zeros
    marks = [[0 for _ in range(tests)] for _ in range(students)]

    # Input marks loop
    print("\n===== ENTER MARKS =====")

    for i in range(students):
        print(f"\nStudent {i + 1}:")

        for j in range(tests):
            try:
                mark_input = input(f"Test {j + 1}: ")
                marks[i][j] = int(mark_input)
            except ValueError:
                marks[i][j] = 0

    print("\n\n===== RESULT ANALYSIS =====")

    # Final Analysis: crunching the numbers for each student
    for i in range(students):
        # Grab all our metrics first
        fail_streak = consecutive_failures(marks[i], tests)
        
        final_score = calculate_weighted_score(marks[i], tests)

        trend_risk = declining_trend(marks[i], tests)

        print(f"\nStudent {i + 1}")

        # Output formatting to 2 decimal places so it looks clean
        print(f"Weighted Score: {final_score:.2f}")

        # Risk Detection based on final weighted score thresholds
        if final_score >= 70:
            print("Status: PREPARED")
        elif final_score >= 55:
            print("Status: NEEDS ATTENTION")
        else:
            print("Status: EXTRA CLASSES REQUIRED")

        # Alert if the student is slacking recently
        if trend_risk:
            print("Warning: Declining Performance Trend")

        # Alerts based on how many times they failed in a row
        if fail_streak == 2:
            print("Warning: Consecutive Failures")
        elif fail_streak > 2:
            print("Critical Alert: Multiple Consecutive Failures")

        print("-------------------------")

if __name__ == "__main__":
    main()
