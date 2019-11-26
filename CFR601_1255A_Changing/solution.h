#ifndef solution_h
#define solution_h

class Solution {
public:
    int getMinimumNumberOfPresses(int left, int right) {
        if(left == right) {
            return 0;
        }
        if(left > right) {
            return getMinimumNumberOfPresses(right, left);
        }
        
        int diff = right - left;
        if(diff / 5 > 0) {
            if(diff % 5 < 3) {
                return diff / 5 + getMinimumNumberOfPresses(left + diff / 5 * 5, right);
            } else
            {
                return diff / 5 + 1 + getMinimumNumberOfPresses(right, left + (diff / 5 + 1) * 5);
            }
        } else if(diff / 2 > 0) {
            if(diff % 2 == 0) {
                return diff / 2;
            } else {
                return diff / 2 + 1;
            }
        }
        return 1;
    }
};

#endif
