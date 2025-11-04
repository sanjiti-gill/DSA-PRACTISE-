#include <iostream>
using namespace std;

int linearsearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // found
        }
    }
    return -1; 
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = linearsearch(arr, n, key);

    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at position " << result + 1;

    return 0;
}
