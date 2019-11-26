#ifndef solution_h
#define solution_h

#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> getPermutation(std::vector<int> prefixMaximums) {
        std::vector<int> p(prefixMaximums.size());
        std::vector<int> impossible = { -1 };
        
        std::vector<int> missing = getMissingValues(prefixMaximums);
        sort(missing.begin(), missing.end());
        int missingIndex = 0;
        
        for(int i = 0; i < prefixMaximums.size(); i++) {
            if(i == 0) {
                p[i] = prefixMaximums[i];
            } else if (prefixMaximums[i] != prefixMaximums[i - 1]){
                if(prefixMaximums[i] < p[i - 1]) {
                    return impossible;
                }
                p[i] = prefixMaximums[i];
            } else {
                if(missingIndex > missing.size()) {
                    return impossible;
                }
                int value = missing[missingIndex++];
                if(value > p[i - 1] && value > prefixMaximums[i]) {
                    return impossible;
                }
                p[i] = value;
            }
        }
        
        if(missing.size() != missingIndex) {
            return impossible;
        }
        
        for(int i = 0; i < p.size(); i++) {
            int e = p[i];
            if(!(1 <= e && e <= p.size())) {
                return impossible;
            }
        }
        
        return p;
    }
private:
    std::vector<int> getMissingValues(std::vector<int> permutation) {
        std::unordered_set<int> elements;
        for(int i = 1; i <= permutation.size(); i++) {
            elements.insert(i);
        }
        for(const int e : permutation) {
            elements.erase(e);
        }
        std::vector<int> missing;
        for(const int e : elements) {
            missing.emplace_back(e);
        }
        return missing;
    }
};

#endif
