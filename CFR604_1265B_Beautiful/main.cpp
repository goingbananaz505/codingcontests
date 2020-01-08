#include <iostream>
#include <vector>
#include <functional>
#include "../Utils/consoleutils.h"
#include "solution.h"

int main() {
    namespace cu = consoleutils;
    using namespace std;
 
    Solution solution;
    cu::runOverMultipleTestsInput([&](const int testId) {
        vector<int> p = cu::readSizeAndArray<int>();
        
        cout << solution.getBeautifulNumbersString(p) << endl;
    });
    return 0;
}
