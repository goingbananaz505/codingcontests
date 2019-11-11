#include <iostream>
#include <vector>

using namespace std;

class CustomFunction {
public:
    int f(int x, int y) {
        return x + y;
    }
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        for(int i = 1; i <= 1000; i++)
            for(int j = 1; j <= 1000; j++)
                if(customfunction.f(i, j) == z) {
                    vector<int> sol = { i, j };
                    result.emplace_back(sol);
                }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    CustomFunction f; int z = 5;
    
    Solution s;
    auto solution = s.findSolution(f, z);
    for(const auto& pair : solution) {
        cout << pair[0] << " " << pair[1] << endl;
    }
    
    return 0;
}
