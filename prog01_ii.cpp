#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int high, int mid){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int comparisons = 0;
    while(left <= mid && right <= high){
        comparisons++;
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
    return comparisons;
}

int mergeS(vector<int> &arr, int low, int high){
    if(low == high) return 0;
    int mid = (low + high) / 2;
    int leftComparisons = mergeS(arr, low, mid);
    int rightComparisons = mergeS(arr, mid + 1, high);
    int mergeComparisons = merge(arr, low, high, mid);
    return leftComparisons + rightComparisons + mergeComparisons;
}

void mergeSort(vector<int> &arr, int n){
    int comparisons = mergeS(arr, 0, n - 1);
    cout << "Number of comparisons: " << comparisons << endl;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Given array is \n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    mergeSort(arr, n);
    cout << "Sorted array is \n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

