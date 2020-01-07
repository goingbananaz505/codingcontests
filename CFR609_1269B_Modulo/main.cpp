#include <iostream>
#include <string>
#include <vector>
#include "../Utils/consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main() {
    int n = cu::read<int>();
    int m = cu::read<int>();
    auto a = cu::readArray<int>(n);
    auto b = cu::readArray<int>(n);
    cout << solution.getAdditionValueForModuloEquality(a, b, m) << endl;
    return 0;
}
