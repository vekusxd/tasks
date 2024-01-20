#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr){
    int max = *std::max_element(arr.begin(), arr.end());

    std::vector<int> temp(max + 1, 0);
    for(const int& n : arr){
        temp[n]++;
    }

    int j = 0;
    for(int i = 0; i < temp.size(); i++){
        while(temp[i] != 0){
            arr[j] = i;
            j++;
            temp[i]--;
        }
    }
}

int main(){
    std::vector<int> arr{20,1,2,3, 11, 15, 18, 10, 8, 65,7,5,3,2,12,4,56,7};

    for(const int& n : arr){
        std::cout << n << " ";
    }


    countingSort(arr);


    std::cout << std::endl;
    for(const int& i : arr){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}