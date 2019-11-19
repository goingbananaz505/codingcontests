#include <vector>

class CustomFunction {
public:
    int f(int x, int y) {
        return x + y;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> findSolution(CustomFunction& customfunction, int z) {
        std::vector<std::vector<int>> result;
        for(int i = 1; i <= 1000; i++)
            for(int j = 1; j <= 1000; j++)
                if(customfunction.f(i, j) == z) {
                    std::vector<int> sol = { i, j };
                    result.emplace_back(sol);
                }
        return result;
    }
};
