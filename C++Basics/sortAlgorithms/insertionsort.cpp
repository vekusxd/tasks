#include <vector>
#include <iostream>
#include <chrono>

using namespace std::chrono;

template<typename T>
void insertionSort(std::vector<T>& arr){
    for(int i = 1; i < arr.size(); i++){
        int j = i - 1;
        T temp = arr[i];
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main(){
      std::vector<int> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9,32,4,5,6,7,8,543,3,12,34,5,6,43,1,2,3,54,5,56,7,57,7,45,35};

    auto start = high_resolution_clock::now();

    insertionSort(arr);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);
 
    std::cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << std::endl;

}