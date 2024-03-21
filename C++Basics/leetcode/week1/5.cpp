#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](const int& a, const int& b){return a > b;});
        return (nums[0] - 1) * (nums[1] - 1);
    }
};

int main(){
    
}