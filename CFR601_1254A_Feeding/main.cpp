#include <iostream>
#include <vector>
#include "../Utils/consoleutils.h"
#include "../Utils/datautils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;
namespace du = datautils;
Solution solution;

int main() {
    cu::runOverMultipleTestsInput([](const int testId) {
        int r = cu::read<int>();
        int c = cu::read<int>();
        int k = cu::read<int>();
        du::matrix<char> map(r);
        for(int i = 0; i < r; i++) {
            map[i] = cu::readArray<char>(c);
        }

        solution.updateMapByAssigningChickens(map, k);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cout << map[i][j];
            }
            cout << endl;
        }
    });
    return 0;
}
