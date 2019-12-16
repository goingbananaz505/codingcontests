#include <iostream>
#include "../Utils/consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main() {
    cu::runOverMultipleTestsInput([](const int testId) {
        int a = cu::read<int>();
        int b = cu::read<int>();
        
        cout << solution.getMinimumNumberOfPresses(a, b) << endl;
    });
    return 0;
}
