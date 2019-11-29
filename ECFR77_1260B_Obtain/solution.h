#ifndef solution_h
#define solution_h

#include <algorithm>

class Solution {
public:
    bool canBeEqualSimultaneously(int a, int b) const {
        if(a > b) {
            std::swap(a, b);
        }
        
        int areGoingToBeEqualAt = a - (b - a);
        if(areGoingToBeEqualAt < 0) {
            return false;
        }
        
        return (areGoingToBeEqualAt % 3 == 0);
    }
};

#endif
