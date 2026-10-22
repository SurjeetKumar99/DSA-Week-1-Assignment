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
    int left=0,right=n-1;
    while (left<right) { swap(arr[left],arr[right]); left++; right--; }
    cout << "Reversed array: ";
    for (int i=0;i<n;i++) cout << arr[i] << " ";
    cout << "\\n";
    return 0;
}
