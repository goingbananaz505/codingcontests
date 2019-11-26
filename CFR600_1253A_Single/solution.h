#ifndef solution_h
#define solution_h

#include <vector>

class Solution {
public:
    bool isSinglePushPossible(const std::vector<int>& A, const std::vector<int>& B) const {
        bool isBeforeKInterval = true;
        bool isAfterKInterval = false;
        int KValue = 0;
        for(int i = 0; i < A.size(); i++) {
            int diff = B[i] - A[i];
            if(diff < 0) {
                return false;
            }
            
            bool isInKInterval = !isBeforeKInterval && !isAfterKInterval;
            
            if(isBeforeKInterval && diff != 0) {
                KValue = diff;
                isBeforeKInterval = false;
                continue;
            }
            
            if(isInKInterval && diff != KValue) {
                if(diff != 0) {
                    return false;
                }
                isAfterKInterval = true;
                continue;
            }
            
            if(isAfterKInterval && diff != 0) {
                return false;
            }
        }
        
        return true;
    }
};

#endif
