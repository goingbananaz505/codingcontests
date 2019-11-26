#include <iostream>
#include <vector>
#include "consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main() {
    cu::runOverMultipleTestsInput([](const int testId) {
        int n = cu::read<int>();
        int m = cu::read<int>();
        vector<int> w = cu::readArray<int>(n);
        
        vector<pair<int, int>> edges;
        int cost = solution.getCostPrivatizingFridges(w, m, edges);
        cout << cost << endl;
        if(cost != -1) {
            for(const auto& pair : edges) {
                cout << pair.first << " " << pair.second << endl;
            }
        }
    });
    return 0;
}
