#include <iostream>
#include <utility>
using namespace std;
int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    if (n<=0 || n>1000) { cout << "Enter a size between 1 and 1000.\\n"; return 0; }
    int arr[1000];
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> arr[i];
    long long swapCount=0;
    for (int i=0;i<n-1;i++) {
        bool swapped=false;
        for (int j=0;j<n-1-i;j++) if (arr[j]>arr[j+1]) {
            swap(arr[j],arr[j+1]); swapCount++; swapped=true;
        }
        if (!swapped) break;
    }
    cout << "Sorted array: ";
    for (int i=0;i<n;i++) cout << arr[i] << " ";
    cout << "\\nTotal swaps: " << swapCount << "\\n";
    return 0;
}
