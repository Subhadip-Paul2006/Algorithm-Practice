# Student Performance Analysis System

## Overview

The **Student Performance Analysis System** is a C++ based academic analytics project designed to identify students who may require extra academic support before examinations.

The system analyzes multiple test performances of students using:

- Weighted Average Analysis
- Declining Trend Detection
- Inconsistency Detection
- Consecutive Failure Detection

The project is designed as a beginner-to-intermediate level Data Structures and Algorithms practice project.

---

# Problem Statement

In a university or academic environment, teachers often need to identify students who are:

- academically weak,
- losing consistency,
- showing declining performance,
- or repeatedly failing.

Traditional average-based evaluation systems are often inaccurate because:

# Student Performance Analysis System

## Overview

The Student Performance Analysis System is a small C++ academic-analytics project that helps identify students who may need extra academic support before examinations.

It analyzes multiple test results using these rule-based checks:

- Weighted average (later tests weighted higher)
- Declining trend detection
- Inconsistency detection
- Consecutive failure detection

This repository is suitable for beginner-to-intermediate practice with algorithms and basic C++ programming.

---

## Problem Statement

Teachers need tools to flag students who are weak, inconsistent, declining, or repeatedly failing. Simple arithmetic averages can hide these problems because they treat all tests equally and ignore recent performance trends.

This project demonstrates a set of lightweight rules that produce actionable alerts for instructors.

---

## Core Objectives

- Accept dynamic input (number of students and tests)
- Store marks in a 2D matrix
- Generate test weights automatically
- Compute weighted scores
- Detect weak students, declining trends, inconsistent performance, and consecutive failures

---

## Technologies Used

- Language: C++ (standard library)
- Concepts: vectors, 2D arrays, functions, loops, simple statistics

---

## Project Structure

```text
Student-Performance-Analysis-System/
│
├── README.md
├── Part01.cpp    # Weighted score + basic classification
├── Part02.cpp    # Adds declining-trend detection
├── Part03.cpp    # Adds inconsistent-performance detection
└── Part04.cpp    # Adds consecutive-failure detection
```

---

## How to run

Compile with a C++ compiler (g++, clang++, or MSVC). Example using g++:

```bash
g++ Part04.cpp -o analysis
./analysis
```

Use the latest Part (Part04.cpp) to get all rules applied; earlier files are incremental stages.

---

## Analysis Steps (implementation summary)

1. Input: number of students and number of tests.
2. Create a matrix: `vector<vector<int>> marks(students, vector<int>(tests));`
3. Weight generation: returns `testNumber + 1`, so later tests carry more weight.
4. Weighted score: Σ(marks[i] \* weight[i]) / Σ(weight[i]).

---

## Rule Details

### Part 01 — Weighted Classification (Part01.cpp)

- Objective: compute a weighted score and classify students.
- Classification:
  - `>= 70` : PREPARED
  - `55–69` : NEEDS ATTENTION
  - `< 55` : EXTRA CLASSES REQUIRED

### Part 02 — Declining Trend (Part02.cpp)

- Objective: detect if recent performance has dropped significantly.
- Logic: compute overall average and a recent-window average. Flag if:

  Recent Average < Overall Average - 15

- Recent window size is dynamic:
  - total tests = 4 -> last 2 tests
  - total tests 5–8 -> last 3 tests
  - total tests >8 -> last 5 tests

### Part 03 — Inconsistent Performance (Part03.cpp)

- Objective: detect high variation between a student's best and worst test.
- Logic: compute `highest - lowest`. If variation >= 35, the student is flagged as inconsistent.

### Part 04 — Consecutive Failures (Part04.cpp)

- Objective: detect streaks of failing marks (failing mark < 40).
- Logic: compute the maximum consecutive failures in the sequence. Alerts:
  - `== 2` : Warning: Consecutive Failures
  - `> 2` : Critical Alert: Multiple Consecutive Failures

---

## Future Improvements

- Graphical dashboard or simple web UI
- Persist data to files or a database
- Subject-wise analytics and ranking
- Exportable reports (CSV/PDF)
- More sophisticated statistical measures (variance, stddev)

---

## Learning Outcomes

- Algorithmic thinking for simple analytics
- Basic C++ data structures and I/O
- Rule-based alerting and heuristics

---

## Notes

- Use `Part04.cpp` for the most complete implementation; earlier files (Part01–Part03) add features incrementally.
- Filenames and rule thresholds in this README were synchronized with the current source code.

---

If you'd like, I can:

- add compilation scripts, or
- convert the code to a single configurable program, or
- add sample test data and a small runner.
