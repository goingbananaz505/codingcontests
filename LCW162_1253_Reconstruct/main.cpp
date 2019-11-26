#include <iostream>
#include <vector>
#include "solution.h"
#include "datautils.h"

namespace du = datautils;
using namespace std;
Solution s;

int main() {
    int upper = 2;
    int lower = 1;
    vector<int> colsum = { 1, 1, 1 };
    
    du::matrix<int> matrix = s.reconstructMatrix(upper, lower, colsum);
    for(const auto& row : matrix) {
        for(const auto& element : row)
            cout << element << " ";
        cout << endl;
    }
    
    return 0;
}
