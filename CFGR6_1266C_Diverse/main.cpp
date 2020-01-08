#include <iostream>
#include <string>
#include <vector>
#include "../Utils/consoleutils.h"
#include "../Utils/datautils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;
namespace du = datautils;
Solution solution;
int main() {
    int r = cu::read<int>();
    int c = cu::read<int>();
    du::matrix<int> m;
    
    if(!solution.isDiverseMatrixPossible(r, c, m)) {
        cout << 0 << '\n';
    } else {
        for(const auto& row : m) {
            for(const int e : row) {
                cout << e << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}
