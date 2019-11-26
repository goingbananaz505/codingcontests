#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;
Solution s;

int main() {
    vector<vector<int>> grid = {
        { 1, 1, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 1 }
    };
    cout << s.countServers(grid) << endl;
    return 0;
}
