#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high, int& comparisons){
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[low]);

    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high){
            i++;
            comparisons++;
        }
        while(arr[j] > pivot && j >= low){
            j--;
            comparisons++;
        }
        if(i < j){ 
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high, int& comparisons){
    if(low < high){
        int pIndex = partition(arr, low, high, comparisons);
        qs(arr, low, pIndex - 1, comparisons);
        qs(arr, pIndex + 1, high, comparisons); 
    }
}

void quickSort(vector<int> &arr){
    int comparisons = 0;
    srand(time(NULL));
    qs(arr, 0, arr.size()-1, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Given array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    quickSort(arr);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

