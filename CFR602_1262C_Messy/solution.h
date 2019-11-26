#ifndef solution_h
#define solution_h

#include <vector>
#include <string>
#include <utility>

class Solution {
public:
    std::vector<std::pair<int, int>> getPairs(std::string s, const int k) const {
        std::vector<std::pair<int, int>> result;
        
        for(int i = 0; i < 2 * (k - 1); i += 2) {
            char first = s[i];
            char second = s[i + 1];
            if(first == ')') {
                int index = findIndex(s, i, '(');
                std::reverse(s.begin() + i, s.begin() + index + 1);
                result.emplace_back(std::make_pair(indexToOrder(i), indexToOrder(index)));
                second = s[i + 1];
            }
            if(second == '(') {
                int index = findIndex(s, i, ')');
                std::reverse(s.begin() + i + 1, s.begin() + index + 1);
                result.emplace_back(std::make_pair(indexToOrder(i + 1), indexToOrder(index)));
            }
        }
        
        int end = 2 * (k - 1) + ((int)s.size() - 2 * (k - 1)) / 2;
        for(int i = 2 * (k - 1); i < end; i++) {
            char c = s[i];
            if(c == ')') {
                int index = findIndex(s, i, '(');
                std::reverse(s.begin() + i, s.begin() + index + 1);
                result.emplace_back(std::make_pair(i + 1, index + 1));
            }
        }
        
        return result;
    }
private:
    inline int indexToOrder(const int index) const {
        return index + 1;
    }
    
    int findIndex(const std::string& s, const int start, const char toFind) const {
        for(int i = start; i < s.size(); i++) {
            char c = s[i];
            if(c == toFind) {
                return i;
            }
        }
        return -1;
    }
};

#endif
