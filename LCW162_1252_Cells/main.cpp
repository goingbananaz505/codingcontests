#include <iostream>
#include <vector>
#include "solution.h"
#include "../Utils/datautils.h"

using namespace std;
namespace du = datautils;
Solution s;

int main() {
    int n = 2;
    int m = 3;
    du::matrix<int> indices = { { 0, 1 }, { 1, 1 } };
    
    cout << s.oddCells(n, m, indices) << endl;
    
    return 0;
}
