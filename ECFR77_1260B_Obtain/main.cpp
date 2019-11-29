#include <iostream>
#include <vector>
#include "consoleutils.h"
#include "solution.h"

int main() {
    using namespace std;
    namespace cu = consoleutils;

    Solution solution;
    cu::runOverMultipleTestsInput([&](const int testId) {
        int a = cu::read<int>();
        int b = cu::read<int>();
        
        if(solution.canBeEqualSimultaneously(a, b)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    });
    return 0;
}
