#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <numeric>

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

int main(){

}