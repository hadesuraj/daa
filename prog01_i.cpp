#include <iostream>
#include <vector>

template <typename T>
void insertionSort(std::vector<T>& arr, int& comparisons){
    int hole;
    T value;
    for(int i = 1; i < arr.size(); i++){
        value = arr[i];
        hole = i - 1;
        while(hole >= 0 && arr[hole] > value){
            arr[hole + 1] = arr[hole];
            hole = hole - 1;
            comparisons++;
        }
        arr[hole + 1] = value;
    }
}

int main(){
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int comparisons = 0;
    insertionSort(arr, comparisons);

    std::cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::cout << "Number of comparisons: " << comparisons << std::endl;

    return 0;
}

