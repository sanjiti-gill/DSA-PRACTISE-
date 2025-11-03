#include<iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right];   
    int i = left - 1;       

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  
        }
    }

    swap(arr[i + 1], arr[right]);

    return i + 1; 
}

void quicksort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(arr, left, right);

    quicksort(arr, left, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, right);
}

int main() {
    int n;
    cout << "Enter number of elements for array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element: ";
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
