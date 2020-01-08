#ifndef solution_h
#define solution_h

class Solution {
public:
    std::string getBeautifulNumbersString(const std::vector<int>& perm) const {
        auto zeroBased = getPermutationSubstractedWithOneOnEachElement(perm);
        std::vector<int> inv = getPermutationInverse(zeroBased);
        return getBeautifulNumbersBitwise(inv);
    }
private:
    std::vector<int> getPermutationSubstractedWithOneOnEachElement(std::vector<int> p) const {
        std::vector<int> n(p.size());
        for(int i = 0; i < p.size(); i++) {
            n[i] = p[i] - 1;
        }
        return n;
    }
    
    std::vector<int> getPermutationInverse(std::vector<int> p) const {
        std::vector<int> inv(p.size());
        for(int i = 0; i < p.size(); i++) {
            inv[p[i]] = i;
        }
        return inv;
    }
    
    std::string getBeautifulNumbersBitwise(std::vector<int> &inv) const {
        std::string result;
        int min = inv[0];
        int max = inv[0];
        for(int i = 0; i < inv.size(); i++) {
            min = std::min(min, inv[i]);
            max = std::max(max, inv[i]);
            
            if(max - min == i) {
                result += "1";
            } else {
                result += "0";
            }
        }
        return result;
    }
};
 

#endif
