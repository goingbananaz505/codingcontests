#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;
Solution s;

int main() {
    vector<vector<int>> points = {
        { 1,1 }, { 3,4 }, { -1,0 }
    };
    cout << s.minTimeToVisitAllPoints(points) << endl;
}
