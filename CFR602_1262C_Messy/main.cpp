#include <iostream>
#include <string>
#include "../Utils/consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main() {
    cu::runOverMultipleTestsInput([](const int testId) {
        cu::read<int>();
        int k = cu::read<int>();
        string s = cu::read<string>();
        
        vector<pair<int, int>> pairs = solution.getPairs(s, k);
        
        cout << pairs.size() << endl;
        for(const auto& pair : pairs) {
            cout << pair.first << " " << pair.second << endl;
        }
    });
    return 0;
}
