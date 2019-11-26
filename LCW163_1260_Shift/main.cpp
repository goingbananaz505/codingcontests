#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;
Solution s;

int main() {
    vector<vector<int>> grid = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    s.shiftGrid(grid, 1);
    return 0;
}
