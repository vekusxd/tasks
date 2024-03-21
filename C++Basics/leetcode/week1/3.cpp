#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    std::vector<int> twoOutOfThree(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3) {
        std::unordered_set<int> nums(nums1.begin(), nums1.end());
        std::unordered_set<int> nums2_set(nums2.begin(), nums2.end());
        std::unordered_set<int> nums3_set(nums3.begin(), nums3.end());
        std::unordered_set<int> visited;
        std::vector<int> res;
        for(const auto& i : nums2_set){
            if(nums.contains(i) && !visited.contains(i)){
                res.push_back(i);
                visited.insert(i);
            }
            else{
                nums.insert(i);
            }
        }
        for(const auto& i : nums3_set){
            if(nums.contains(i) && !visited.contains(i)){
                res.push_back(i);
                visited.insert(i);
            }
            else{
                nums.insert(i);
            }
        }
        return res;
    }
};

int main(){

}