#include <iostream>
#include <vector>
#include "consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main() {
    int N = cu::read<int>();
    vector<vector<int>> tuples(N - 2);
    for(int i = 0; i < N - 2; i++) {
        tuples[i] = cu::readArray<int>(3);
    }
    
    vector<int> perm = solution.getOriginalPermutation(tuples);
    for(const int e : perm) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
