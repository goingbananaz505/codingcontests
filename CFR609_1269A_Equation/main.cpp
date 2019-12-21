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
    pair<int, int> p = solution.getCompositeNumbersPairWithSubstractionOfValue(n);
    cout << p.first << " " << p.second << '\n';
    return 0;
}
