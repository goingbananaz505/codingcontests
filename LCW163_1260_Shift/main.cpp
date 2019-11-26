#include <iostream>
#include <vector>
#include "solution.h"
#include "datautils.h"

using namespace std;
namespace du = datautils;
Solution s;

int main() {
    du::matrix<int> grid = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    s.shiftGrid(grid, 1);
    return 0;
}
