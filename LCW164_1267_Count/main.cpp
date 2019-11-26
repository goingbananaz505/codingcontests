#include <iostream>
#include <vector>
#include "solution.h"
#include "datautils.h"

namespace du = datautils;

using namespace std;
Solution s;

int main() {
    du::matrix<int> grid = {
        { 1, 1, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 1 }
    };
    cout << s.countServers(grid) << endl;
    return 0;
}
