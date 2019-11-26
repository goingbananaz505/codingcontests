#ifndef solution_h
#define solution_h

#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> getOriginalPermutation(const std::vector<std::vector<int>> tuples) const {
        std::vector<int> permutation(tuples.size() + 2);
        
        PermutationFinder pf(tuples);
        for(int i = 0; i < permutation.size(); i++) {
            permutation[i] = pf.getNextElement();
        }
        
        return permutation;
    }
    
private:
    class PermutationFinder {
    public:
        PermutationFinder(const std::vector<std::vector<int>>& tuples) {
            this->tuples = tuples;
            normalizeTuples();
        }
        void normalizeTuples() {
            for(auto& tuple : this->tuples) {
                for(int& e : tuple) {
                    e--;
                }
            }
        }
        
        int getNextElement() {
            this->getNextElementCallsCount++;
            if(getNextElementCallsCount == 1) {
                initializeSearch();
                currentThreeSizedTupleIndex = getFirstTupleIndex();
                currentThreeSizedTuple = getFirstOrderedTupleByIndex(currentThreeSizedTupleIndex);
                updateSearchContextByFindingTupleIndex(currentThreeSizedTupleIndex);
            }
            
            if(getNextElementCallsCount <= 3) {
                int nextElement = currentThreeSizedTuple[getNextElementCallsCount - 1];
                int denormalizedNextElement = nextElement + 1;
                return denormalizedNextElement;
            }
            
            currentThreeSizedTupleIndex = nextThreeSizedTupleIndex;
            currentThreeSizedTuple = getOrderedTupleByIndex(currentThreeSizedTupleIndex);
            updateSearchContextByFindingTupleIndex(currentThreeSizedTupleIndex);
            
            int nextElement = currentThreeSizedTuple[2];
            int denormalizedNextElement = nextElement + 1;
            return denormalizedNextElement;
        }
        
    private:
        void initializeSearch() {
            searchContext.resize(tuples.size() + 2);
            
            for(int i = 0; i < tuples.size(); i++) {
                for(const int e : tuples[i]) {
                    searchContext[e].insert(i);
                }
            }
        }
        int getFirstTupleIndex() const {
            for(int i = 0; i < searchContext.size(); i++) {
                if(searchContext[i].size() == 1) {
                    return *searchContext[i].begin();
                }
            }
            return -1;
        }
        std::vector<int> getFirstOrderedTupleByIndex(const int index) const {
            std::vector<int> tuple = tuples[index];
            sort(tuple.begin(), tuple.end(), [&](const int a, const int b) -> bool
            {
                return searchContext[a].size() < searchContext[b].size();
            });
            
            return tuple;
        }
        std::vector<int> getOrderedTupleByIndex(const int index) const {
            std::vector<int> tuple(3);
            tuple[0] = currentThreeSizedTuple[1];
            tuple[1] = currentThreeSizedTuple[2];
            if(tuples[index][0] != tuple[0] && tuples[index][0] != tuple[1]) {
                tuple[2] = tuples[index][0];
            } else if(tuples[index][1] != tuple[0] && tuples[index][1] != tuple[1]) {
                tuple[2] = tuples[index][1];
            } else if(tuples[index][2] != tuple[0] && tuples[index][2] != tuple[1]) {
                tuple[2] = tuples[index][2];
            }
            
            return tuple;
        }
        void updateSearchContextByFindingTupleIndex(const int index) {
            std::vector<int>& tuple = this->tuples[index];
            for(const int value : tuple) {
                searchContext[value].erase(index);
                if(searchContext[value].size() == 1) {
                    nextThreeSizedTupleIndex = *searchContext[value].begin();
                }
            }
        }
        
        std::vector<std::vector<int>> tuples;
        int getNextElementCallsCount = 0;
        std::vector<std::unordered_set<int>> searchContext;
        int currentThreeSizedTupleIndex;
        int nextThreeSizedTupleIndex;
        std::vector<int> currentThreeSizedTuple;
    };
};

#endif
