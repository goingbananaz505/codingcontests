#include <iostream>
#include <vector>
#include "../Utils/consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main() {
    cu::runOverMultipleTestsInput([](const int testId) {
        int n = cu::read<int>();
        vector<pair<int, int>> segments(n);
        for(int i = 0; i < n; i++) {
            int x; int y;
            cin >> x >> y;
            segments[i] = make_pair(x, y);
        }
        cout << solution.getLengthOfSegmentIntersectingAll(segments) << endl;
    });
    return 0;
}
