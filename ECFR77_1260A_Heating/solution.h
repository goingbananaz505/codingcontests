#ifndef solution_h
#define solution_h

class Solution {
public:
    int getMinimumCost(const int c, const int sum) const {
        int r = sum % c;
        int k = sum / c;
        
        if(r == 0) {
            return c * k * k;
        } else {
            return r * (k + 1) * (k + 1) + (c - r) * k * k;
        }
    }
};

#endif
