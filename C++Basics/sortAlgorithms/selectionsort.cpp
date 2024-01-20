#include <vector>
#include <iostream>
#include <random>
#include <chrono>

using namespace std::chrono;

template<typename T>
void selectionSort(std::vector<T>& arr){
   for(int i = 0; i < arr.size() - 1; i++){
    int min = i;
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
    std::swap(arr[i], arr[min]);
   }
}

void Random(std::vector<int>& arr){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 1000);

    for(int& n : arr){
        n = dist(gen);
    }
}

int main(){
    std::vector<int> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9,32,4,5,6,7,8,543,3,12,34,5,6,43,1,2,3,54,5,56,7,57,7,45,35};

    auto start = high_resolution_clock::now();

    selectionSort(arr);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);
 
    std::cout << "Time taken by function: "
         << duration.count() << " microseconds" << std::endl;

}