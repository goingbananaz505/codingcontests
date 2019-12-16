#include <iostream>
#include "../Utils/consoleutils.h"
#include "solution.h"

using namespace std;

int main() {
    namespace cu = consoleutils;

    Solution solution;
    cu::runOverMultipleTestsInput([&](const int testId) {
        int a = cu::read<int>();
        int b = cu::read<int>();
        int k = cu::read<int>();
        
        if(solution.isExecutionAvoidable(a, b, k)) {
            cout << "OBEY" << '\n';
        } else {
            cout << "REBEL" << '\n';
        }
    });
    return 0;
}
