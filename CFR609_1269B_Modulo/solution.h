#ifndef solution_h
#define solution_h

#include <map>

class Solution {
public:
    int getAdditionValueForModuloEquality(const std::vector<int>& a,
                                          const std::vector<int>& b,
                                          const int m) const {
        auto mostFreqAs = getMostFrequentValues(a);
        auto mostFreqBs = getMostFrequentValues(b);
        
        int mostFreqA = mostFreqAs[0];
        for(const int& mostFreqB : mostFreqBs) {
            int addition = (mostFreqB - mostFreqA);
            if(addition < 0) {
                addition += m;
            }
            
            if(additionMatches(a, b, m, addition)) {
                return addition;
            }
        }
        
        return 0;
    }
private:
    std::vector<int> getMostFrequentValues(const std::vector<int>& v) const {
        std::map<int, int> counters;
        int max = 0;
        std::vector<int> values;
        for(const int element : v) {
            counters[element]++;
            if(counters[element] == max) {
                values.emplace_back(element);
            } else if(counters[element] > max) {
                max = counters[element];
                values.resize(0);
                values.emplace_back(element);
            }
        }
        
        return values;
    }
    
    bool additionMatches(std::vector<int> a,
                         std::vector<int> b,
                         const int k,
                         const int add) const {
        for(int& e : a) {
            e += add;
            e %= k;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif
