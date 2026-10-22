# Data Structures & Algorithms (DSA) — Week 1 Assignment

Beginner-friendly C++ solutions for the Week 1 DSA assignment: Linear Search, Binary Search, Bubble Sort with swap counting, in-place array reversal, and a Student Marks Analyzer mini-project.

## Topics
- Introduction to Data Structures and Algorithms
- Time and space complexity (Big O)
- Arrays and searching
- Bubble Sort and swap counting
- In-place array reversal
- Student marks analysis

## Learning Objectives
- Understand how data structures organize data and how algorithms solve problems.
- Implement linear and binary search in C++.
- Sort array elements and count swaps.
- Reverse an array without creating a second array.
- Calculate an average and identify the top three marks.

## Repository Structure
```text
DSA_Week_1_GitHub_Project/
├── README.md
├── .gitignore
└── src/
    ├── linear_search.cpp
    ├── binary_search.cpp
    ├── bubble_sort_swap_count.cpp
    ├── reverse_array.cpp
    └── student_marks_analyzer.cpp
```

## Requirements
- C++ compiler (GCC/G++, Clang, or an IDE with C++ support)
- Terminal / Command Prompt

Check compiler installation:
```bash
g++ --version
```

## Compile and Run
Run from the repository root. Example:
```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/linear_search.cpp -o linear_search
./linear_search
```
Compile another program by replacing the source and executable names. On Windows, run the generated `.exe` file.

---

## Assignment 1 — Linear Search

**Problem:** Find a target value by checking array elements one by one. Works on sorted or unsorted arrays.

**File:** `src/linear_search.cpp`

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0 || n > 1000) {
        cout << "Enter a size between 1 and 1000.\\n";
        return 0;
    }

    int arr[1000];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter value to search: ";
    cin >> target;
    int position = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            position = i;
            break;
        }
    }

    if (position == -1) cout << "Value not found.\\n";
    else cout << "Value found at position " << position + 1 << ".\\n";
    return 0;
}
```

**Sample input**
```text
5
12 7 25 9 18
25
```
**Sample output**
```text
Value found at position 3.
```
**Complexity:** Best O(1); average/worst O(n); auxiliary space O(1), excluding the input array.

---

## Assignment 2 — Binary Search

**Problem:** Find a target in an array sorted in ascending order. Binary Search repeatedly halves the search range. **The array must be sorted.**

**File:** `src/binary_search.cpp`

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0 || n > 1000) {
        cout << "Enter a size between 1 and 1000.\\n";
        return 0;
    }

    int arr[1000];
    cout << "Enter " << n << " elements in ascending order: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter value to search: ";
    cin >> target;
    int low = 0, high = n - 1, position = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            position = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (position == -1) cout << "Value not found.\\n";
    else cout << "Value found at position " << position + 1 << ".\\n";
    return 0;
}
```

**Sample input**
```text
6
3 8 12 17 24 31
24
```
**Sample output**
```text
Value found at position 5.
```
**Complexity:** Best O(1); average/worst O(log n); auxiliary space O(1) for the iterative version.

---

## Assignment 3 — Bubble Sort and Swap Count

**Problem:** Sort values in ascending order and count adjacent exchanges. The optimized version stops if a pass makes no swaps.

**File:** `src/bubble_sort_swap_count.cpp`

```cpp
#include <iostream>
#include <utility>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0 || n > 1000) {
        cout << "Enter a size between 1 and 1000.\\n";
        return 0;
    }

    int arr[1000];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\\nTotal swaps: " << swapCount << "\\n";
    return 0;
}
```

**Sample input**
```text
5
5 1 4 2 8
```
**Sample output**
```text
Sorted array: 1 2 4 5 8
Total swaps: 4
```
**Complexity:** Best O(n) with early stopping; average/worst O(n²); auxiliary space O(1).

---

## Assignment 4 — Reverse an Array In-Place

**Problem:** Reverse an array without using another array. Two pointers swap the first and last values and move inward.

**File:** `src/reverse_array.cpp`

```cpp
#include <iostream>
#include <utility>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0 || n > 1000) {
        cout << "Enter a size between 1 and 1000.\\n";
        return 0;
    }

    int arr[1000];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = 0, right = n - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\\n";
    return 0;
}
```

**Sample input**
```text
5
10 20 30 40 50
```
**Sample output**
```text
Reversed array: 50 40 30 20 10
```
**Complexity:** Time O(n); auxiliary space O(1).

---

## Mini Project — Student Marks Analyzer

**Objective:** Read marks for N students, validate each mark (0–100), calculate the average, sort marks in descending order, and print the top three marks (or all marks if fewer than three students are entered).

**File:** `src/student_marks_analyzer.cpp`

```cpp
#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    if (n <= 0 || n > 1000) {
        cout << "Enter a student count between 1 and 1000.\\n";
        return 0;
    }

    double marks[1000], total = 0;
    for (int i = 0; i < n; i++) {
        cout << "Enter marks for student " << i + 1 << " (0-100): ";
        cin >> marks[i];
        if (marks[i] < 0 || marks[i] > 100) {
            cout << "Invalid marks. Marks must be from 0 to 100.\\n";
            return 0;
        }
        total += marks[i];
    }

    // Sort descending with Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (marks[j] < marks[j + 1]) {
                swap(marks[j], marks[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    cout << fixed << setprecision(2);
    cout << "\\nAverage score: " << total / n << "\\n";
    int topCount = (n < 3) ? n : 3;
    cout << "Top " << topCount << " marks: ";
    for (int i = 0; i < topCount; i++) cout << marks[i] << " ";
    cout << "\\n";
    return 0;
}
```

**Sample input**
```text
5
78
92
65
88
77
```
**Sample output**
```text
Average score: 80.00
Top 3 marks: 92.00 88.00 78.00
```
**Average calculation:** (78 + 92 + 65 + 88 + 77) / 5 = 400 / 5 = **80.00**.

**Complexity:** Average calculation O(n); sorting O(n²) average/worst and O(n) best with early stopping. Input storage is O(n); sorting uses O(1) auxiliary space.

---

## Complexity Comparison

| Algorithm | Input requirement | Best time | Average / worst time | Auxiliary space |
|---|---|---:|---:|---:|
| Linear Search | Any array | O(1) | O(n) | O(1) |
| Binary Search | Sorted array | O(1) | O(log n) | O(1) |
| Bubble Sort | Any array | O(n), optimized | O(n²) | O(1) |
| In-place reversal | Any array | O(n) | O(n) | O(1) |
| Student Marks Analyzer | Marks in range 0–100 | O(n) for average | O(n²) overall | O(n) input array |

## Key Learnings
- Linear Search works on unsorted data but may inspect every element.
- Binary Search is faster for large sorted arrays.
- Bubble Sort demonstrates adjacent comparisons and swap counting.
- Two-pointer reversal changes the array in place.
- Arrays can be combined with validation, sorting, and arithmetic to build a small data-analysis application.

## Future Improvements
- Use `std::vector` for dynamically sized arrays.
- Handle non-numeric input safely.
- Compare Bubble Sort with Selection Sort, Merge Sort, and `std::sort`.
- Build a menu-driven program that runs each algorithm.
- Add tests for duplicates, already-sorted input, and missing search values.

## Author
- **Name:** Replace with your name
- **Course:** Replace with your course/class
- **Subject:** Data Structures & Algorithms
- **Assignment:** Week 1 — DSA Fundamentals & Arrays

## License
For educational and learning purposes. Add a license file if you want to define reuse and distribution terms.
