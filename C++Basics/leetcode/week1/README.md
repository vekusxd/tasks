## <Center>LeetCode Week 1<Center>

### [Substrings of Size Three with Distinct Characters](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/)
```cpp
class Solution {
public:
    int countGoodSubstrings(std::string s) {
        if(s.size() < 3)
            return 0;
        int res{};
        for(size_t i = 0; i != s.size() - 2; ++i){
            if(s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2])
                ++res;
        }
        return res;
    }
};
```

#### [Minimum Cost of Buying Candies With Discount](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/)
```cpp
class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        if(cost.size() < 3)
            return std::accumulate(cost.begin(), cost.end(), 0);
        std::sort(cost.begin(), cost.end(), [](const int& a, const int& b){return a > b;});
        int res{};
        auto iter = cost.begin();
        while(iter != cost.end()){
            if(iter + 1 == cost.end() || iter + 2 == cost.end()){
                res += std::accumulate(iter, cost.end(), 0);
                return res;
            }
            res += *iter +  *(iter + 1);
            iter += 3;
        }
        return res;
    }
};
```

### [Two Out of Three](https://leetcode.com/problems/two-out-of-three/)
```cpp
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
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
```

### [Count the Number of Vowel Strings in Range](https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/)
```cpp
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        auto start = words.begin() + left;
        auto end = words.begin() + right + 1;

        auto isVowel = [](const char& ch){
            return ch  == 'a' || ch =='e'||
             ch =='i' || ch =='o' || ch =='u';
        };

        return std::count_if(start, end, [&isVowel](const std::string& s){
            return isVowel(s.front()) && isVowel(s.back());
        });
    }
};
```

### [Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](const int& a, const int& b){return a > b;});
        return (nums[0] - 1) * (nums[1] - 1);
    }
};
```