#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;
int main() {
    int n;
    cout << "Enter number of students: "; cin >> n;
    if (n<=0 || n>1000) { cout << "Enter a student count between 1 and 1000.\\n"; return 0; }
    double marks[1000],total=0;
    for (int i=0;i<n;i++) {
        cout << "Enter marks for student " << i+1 << " (0-100): "; cin >> marks[i];
        if (marks[i]<0 || marks[i]>100) { cout << "Invalid marks. Marks must be from 0 to 100.\\n"; return 0; }
        total+=marks[i];
    }
    for (int i=0;i<n-1;i++) {
        bool swapped=false;
        for (int j=0;j<n-1-i;j++) if (marks[j]<marks[j+1]) {
            swap(marks[j],marks[j+1]); swapped=true;
        }
        if (!swapped) break;
    }
    cout << fixed << setprecision(2);
    cout << "\\nAverage score: " << total/n << "\\n";
    int topCount=(n<3)?n:3;
    cout << "Top " << topCount << " marks: ";
    for (int i=0;i<topCount;i++) cout << marks[i] << " ";
    cout << "\\n";
    return 0;
}
