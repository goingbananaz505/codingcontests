#include <iostream>
#include "../Utils/consoleutils.h"
#include "solution.h"

int main() {
    using namespace std;
    namespace cu = consoleutils;

    Solution solution;
    cu::runOverMultipleTestsInput([&](const int testId) {
        int c = cu::read<int>();
        int sum = cu::read<int>();
        
        cout << solution.getMinimumCost(c, sum) << endl;
    });
    return 0;
}
