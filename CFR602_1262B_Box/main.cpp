#include <iostream>
#include <vector>
#include "../Utils/consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main() {
    cu::runOverMultipleTestsInput([](const int testId) {
        auto q = cu::readSizeAndArray<int>();
        vector<int> p = solution.getPermutation(q);
        for(const int e : p) {
            cout << e << " ";
        }
        cout << endl;
    });
    return 0;
}
