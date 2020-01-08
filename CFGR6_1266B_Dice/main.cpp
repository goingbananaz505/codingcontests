#include <iostream>
#include <string>
#include <vector>
#include "../Utils/consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main(int argc, const char * argv[]) {
    cu::runOverMultipleTestsInput([](const int testId) {
        int long long x = cu::read<int long long>();
        if(solution.isPossibleBuildingDiceTower(x)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    });
    return 0;
}
