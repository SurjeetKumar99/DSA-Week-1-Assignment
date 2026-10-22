#include <iostream>
using namespace std;
int main() {
    int n,target;
    cout << "Enter number of elements: "; cin >> n;
    if (n<=0 || n>1000) { cout << "Enter a size between 1 and 1000.\\n"; return 0; }
    int arr[1000];
    cout << "Enter " << n << " elements in ascending order: ";
    for (int i=0;i<n;i++) cin >> arr[i];
    cout << "Enter value to search: "; cin >> target;
    int low=0, high=n-1, position=-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]==target) { position=mid; break; }
        else if (arr[mid]<target) low=mid+1;
        else high=mid-1;
    }
    if (position==-1) cout << "Value not found.\\n";
    else cout << "Value found at position " << position+1 << ".\\n";
    return 0;
}
