#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
    int countGoodSubstrings(std::string s) {
        if(s.size() < 3)
            return 0;
        int res{};
        for(size_t i = 0; i != s.size() - 2; ++i){
            if(s[i] != s[i + 1] && s[i + 1] != s[i + 2]  && s[i] != s[i + 2])
                ++res;
        }
        return res;
    }
};

int main(){

}