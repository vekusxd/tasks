#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
    int vowelStrings(std::vector<std::string>& words, int left, int right) {
        auto start = words.begin() + left;
        auto end = words.begin() + right + 1;

        auto isVowel = [](const char& ch){
            return ch  == 'a' || ch =='e' || ch =='i' || ch =='o' || ch =='u';
        };

        return std::count_if(start, end, [&isVowel](const std::string& s){
            return isVowel(s.front()) && isVowel(s.back());
        });
    }
};

int main(){

}