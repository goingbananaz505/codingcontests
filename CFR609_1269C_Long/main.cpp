#include <iostream>
#include <string>
#include <vector>
#include "../Utils/consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main() {
    cu::read<int>();
    int k = cu::read<int>();
    string x = cu::read<string>();
    string beautiful = solution.getBeautifulNumberGreaterThan(x, k);
    cout << beautiful.size() << '\n' << beautiful << '\n';
    return 0;
}
