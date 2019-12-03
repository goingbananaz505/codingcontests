#include <iostream>
#include <vector>
#include "solution.h"
#include "consoleutils.h"

Solution s;
int main() {
    using namespace std;
    namespace cu = consoleutils;
    
    const std::vector<int> map = cu::readSizeAndArray<int>();
    cout << s.getPresentRedistributionCost(map) << endl;
    return 0;
}
