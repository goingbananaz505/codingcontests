#include <iostream>
#include <string>
#include <vector>
#include "../Utils/consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main() {
    cu::runOverMultipleTestsInput([](const int testId) {
        string p = cu::read<string>();
        string h = cu::read<string>();
        if(solution.isShuffleHashing(p, h)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    });
}
