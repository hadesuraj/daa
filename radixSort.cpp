#include<bits/stdc++.h>
using namespace std;
int getMax(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void countSort(vector<int>& arr, int exp, int &pass) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    pass++;
}
void radixSort(vector<int>& arr) {
    int m = getMax(arr);
    int pass = 0;
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, exp, pass);
    }
    cout << "Number of passes: " << pass << endl;
}
void printArr(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    radixSort(arr);
    cout << "Sorted array: ";
    printArr(arr);
    return 0;
}

