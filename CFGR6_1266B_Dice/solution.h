#ifndef solution_h
#define solution_h

class Solution {
public:
    bool isPossibleBuildingDiceTower(const int long long x) const {
        if(x < 14) {
            return false;
        }
        
        int long long r = x % 14;
        if(1 <= r && r <= 6) {
            return true;
        }
        return false;
    }
private:
    
};

#endif
