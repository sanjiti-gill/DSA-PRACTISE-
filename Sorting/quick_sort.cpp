#include<iostream>
using namespace std;

int partition(int arr[], int left, int right){
    int pivot=arr[left];
    int i=left+1;
    int j=right;

    while(true){
        while(i<=right && arr[i]<=pivot){
            i++;
        }
        while(j>=left+1 && arr[j]>pivot){
            j--;
        }
        if(i>j){
            break;
        }

        swap(arr[i],arr[j]);
    }

    swap(arr[left],arr[j]);
    return j;
}

void quicksort(int arr[], int left, int right){
    if(left>=right){
        return;
    }

    int pivotindex=partition(arr,left,right);

    quicksort(arr,left,pivotindex-1);
    quicksort(arr,pivotindex+1,right);
}

int main(){
    int n;
    cout << "enter number of elements for array: " ;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cout << "enter element: " ;
        cin >> arr[i];
    }

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}
