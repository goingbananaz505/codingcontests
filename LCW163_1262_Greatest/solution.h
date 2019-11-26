#ifndef solution_h
#define solution_h

#include <vector>
#include <numeric>

class Solution {
public:
    int maxSumDivThree(const std::vector<int>& nums) const {
        std::vector<std::vector<int>> groups = getGroupedByModuloThree(nums);
        sortGroups(groups);
        const std::vector<int>& mod3Equals0 = groups[0];
        const std::vector<int>& mod3Equals1 = groups[1];
        const std::vector<int>& mod3Equals2 = groups[2];

        int sum = getSum(mod3Equals0) +
            getSum(mod3Equals1) + getSum(mod3Equals2);
        bool canSelectAllNumbersModuloThreeEqualsOneAndTwo =
            ((mod3Equals1.size() % 3) == (mod3Equals2.size() % 3));
        if(!canSelectAllNumbersModuloThreeEqualsOneAndTwo) {
            int extra = 0;
            std::vector<int> mod3Eq1few = getFirstFewElements(mod3Equals1);
            std::vector<int> mod3Eq2few = getFirstFewElements(mod3Equals2);
            if(mod3Eq1few.size() == 0) {
                if(mod3Eq2few.size() == 0) {
                    extra = 0;
                } else if(mod3Eq2few.size() == 1) {
                    extra = mod3Eq2few[0];
                } else if(mod3Eq2few.size() == 2) {
                    extra = mod3Eq2few[0] + mod3Eq2few[1];
                } else if(mod3Eq2few.size() == 3) {
                    extra = 0;
                }
            } else if(mod3Eq1few.size() == 1) {
                if(mod3Eq2few.size() == 0) {
                    extra = mod3Eq1few[0];
                } else if(mod3Eq2few.size() == 1) {
                    extra = 0;
                } else if(mod3Eq2few.size() == 2) {
                    extra = mod3Eq2few[0];
                } else if(mod3Eq2few.size() == 3) {
                    extra = std::min(mod3Eq1few[0], mod3Eq2few[0] + mod3Eq2few[1]);
                }
            } else if(mod3Eq1few.size() == 2) {
                if(mod3Eq2few.size() == 0) {
                    extra = mod3Eq1few[0];
                } else if(mod3Eq2few.size() == 1) {
                    extra = mod3Eq1few[0];
                } else if(mod3Eq2few.size() == 2) {
                    extra = 0;
                } else if(mod3Eq2few.size() == 3) {
                    extra = std::min(mod3Eq2few[0], mod3Eq1few[0] + mod3Eq1few[1]);
                }
            } else if(mod3Eq1few.size() == 3) {
                if(mod3Eq2few.size() == 0) {
                    extra = mod3Eq1few[0];
                } else if(mod3Eq2few.size() == 1) {
                    extra = std::min(mod3Eq2few[0], mod3Eq1few[0] + mod3Eq1few[1]);
                } else if(mod3Eq2few.size() == 2) {
                    extra = std::min(mod3Eq1few[0], mod3Eq2few[0] + mod3Eq2few[1]);
                } else if(mod3Eq2few.size() == 3) {
                    extra = 0;
                }
            }
            
            sum -= extra;
        }
        
        return sum;
    }
private:
    std::vector<std::vector<int>> getGroupedByModuloThree(const std::vector<int>& nums) const {
        std::vector<std::vector<int>> groups(3);
        for(const int& x : nums) {
            groups[x % 3].emplace_back(x);
        }
        return groups;
    }
    void sortGroups(std::vector<std::vector<int>>& groups) const {
        for(std::vector<int>& group : groups) {
            sort(group.begin(), group.end());
        }
    }
    int getSum(const std::vector<int>& numbers) const {
        return std::accumulate(numbers.begin(), numbers.end(), 0);
    }
    
    std::vector<int> getFirstFewElements(const std::vector<int>& elements) const {
        std::vector<int> result;
        if(elements.size() == 0) {
            return result;
        }
        
        int count = elements.size() % 3;
        if(count == 0) { count += 3; }

        for(int i = 0; i < count; i++) {
            result.emplace_back(elements[i]);
        }
        return result;
    }
};

#endif
