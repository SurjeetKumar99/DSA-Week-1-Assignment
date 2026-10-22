#include <iostream>
using namespace std;
int main() {
    int n, target;
    cout << "Enter number of elements: "; cin >> n;
    if (n <= 0 || n > 1000) { cout << "Enter a size between 1 and 1000.\\n"; return 0; }
    int arr[1000];
    cout << "Enter " << n << " elements: ";
    for (int i=0;i<n;i++) cin >> arr[i];
    cout << "Enter value to search: "; cin >> target;
    int position=-1;
    for (int i=0;i<n;i++) if (arr[i]==target) { position=i; break; }
    if (position==-1) cout << "Value not found.\\n";
    else cout << "Value found at position " << position+1 << ".\\n";
    return 0;
}
