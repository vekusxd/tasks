## <center>LeetCode Week 2<center>

### [Missing Number](https://leetcode.com/problems/missing-number/description/)

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::unordered_set set(nums.begin(), nums.end());
        int max = *(std::max_element(set.begin(), set.end()));

        for(int i = 0; i != max + 1; ++i){
            if(!set.contains(i))
                return i;
        }
        return set.size();
    }
};
```

### [Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string/)

```cpp
class Solution {
public:
    string removeStars(string s) {
        std::string res;
        for(const auto& ch : s){
            if(ch == '*'){
                res.pop_back();
            }
            else{
                res.push_back(ch);
            }
        }
        return res;
    }
};
```

### [Count Operations to Obtain Zero](https://leetcode.com/submissions/detail/1216502024/)

```cpp
class Solution {
public:
    int countOperations(int num1, int num2) {
        int counter{};
        while(num1 != 0 && num2!= 0){
            if(num1 >= num2){
                num1 -= num2;
            }
            else{
                num2 -= num1;
            }
            ++counter;
        }
        return counter;
    }
};
```

### [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res{};
        int sell = prices.front();
        for(auto iter = prices.begin() + 1; iter != prices.end(); ++iter){
                int temp = *iter;
                if(temp > sell){
                    res = std::max(res, temp - sell);
                }
                else{
                    sell = temp;
                }
            }
            return res;
    }
};
```

### [Find Valid Matrix Given Row and Column Sums](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/)

```cpp
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        std::vector<std::vector<int>> res;
        for(int& i : rowSum){
            std::vector<int> toPush;
            for(int& j : colSum){
                int temp = std::min(i, j);
                toPush.push_back(temp);
                i -= temp;
                j -= temp;
            }
            res.push_back(toPush);
        }
        return res;
    }
};
```