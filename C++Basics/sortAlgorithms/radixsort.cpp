#include <iostream>
#include <vector>
#include <algorithm>

void radixSort(std::vector<int>& arr){
    std::vector<std::vector<int>> toCount(10);

    int max = *std::max_element(arr.begin(), arr.end());
    int rank = 1;
    while(max - rank >= 0){
        for(int& n : arr){
            int temp = n / rank;
            toCount[temp % 10].push_back(n);
        }

        int j = 0;
        for(auto &vector : toCount){
            while(!vector.empty()){
                int first = vector[0];
                vector.erase(vector.begin());
                arr[j] = first;
                j++;
            }
        }
    rank *= 10;
    }
}


int main(){
    std::vector<int> arr{23,45,1,2,3,4,56,67,7,1245,23,4354,34,21,345};
    for(const int& n : arr){
        std::cout << n << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    for(const int& n : arr){
        std::cout << n << " ";
    }
    std::cout << std::endl;

}