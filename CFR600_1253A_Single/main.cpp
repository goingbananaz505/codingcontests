#include <iostream>
#include <vector>
#include "solution.h"
#include "../Utils/consoleutils.h"

using namespace std;
namespace cu = consoleutils;
Solution s;
 
int main() {
    cu::runOverMultipleTestsInput([](const int testId) {
        int N = cu::read<int>();
        vector<int> A = cu::readArray<int>(N);
        vector<int> B = cu::readArray<int>(N);
        
        if(s.isSinglePushPossible(A, B)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    });
    return 0;
}
