#ifndef solution_h
#define solution_h

#include <vector>
#include <utility>

class Solution {
public:
    int getCostPrivatizingFridges(const std::vector<int>& weights,
                                  int numberOfChains,
                                  std::vector<std::pair<int, int>>& edges) {
        if(numberOfChains < weights.size()) {
            return -1;
        }
        
        if(weights.size() <= 2) {
            return -1;
        }
        
        std::vector<int> mins = {
            std::numeric_limits<int>::max(),
            std::numeric_limits<int>::max() };
        std::vector<int> pos = { -1, -1 };
        int sum = 0;
        for(int i = 0; i < weights.size(); i++) {
            const int w = weights[i];
            
            sum += w;
            if(w < mins[1]) {
                mins[1] = w;
                pos[1] = i;
            }
            if(mins[1] < mins[0]) {
                std::swap(mins[0], mins[1]);
                std::swap(pos[0], pos[1]);
            }
        }
        
        for(int i = 0; i < weights.size(); i++) {
            int secondNode = (i + 1) % weights.size();
            edges.emplace_back(std::make_pair(i + 1, secondNode + 1));
        }
        
        for(int i = 0; i < numberOfChains - weights.size(); i++) {
            edges.emplace_back(std::make_pair(pos[0] + 1, pos[1] + 1));
        }
        int costOfMakingAllFridgesPrivate = 2 * sum;
        int remainingEdgesToBeAdded = numberOfChains - static_cast<int>(weights.size());
        int costOfTheCheapestEdge = mins[0] + mins[1];
        return costOfMakingAllFridgesPrivate + remainingEdgesToBeAdded * costOfTheCheapestEdge;
    }
};

#endif
