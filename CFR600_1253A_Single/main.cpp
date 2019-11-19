#include <iostream>
#include <vector>
#include "consoleutils.h"

using namespace std;
namespace cu = consoleutils;

bool isSinglePushPossible(const vector<int>& A, const vector<int>& B) {
    bool isBeforeKInterval = true;
    bool isAfterKInterval = false;
    int KValue = 0;
    for(int i = 0; i < A.size(); i++) {
        int diff = B[i] - A[i];
        if(diff < 0) {
            return false;
        }
        
        bool isInKInterval = !isBeforeKInterval && !isAfterKInterval;
        
        if(isBeforeKInterval && diff != 0) {
            KValue = diff;
            isBeforeKInterval = false;
            continue;
        }
        
        if(isInKInterval && diff != KValue) {
            if(diff != 0) {
                return false;
            }
            isAfterKInterval = true;
            continue;
        }
        
        if(isAfterKInterval && diff != 0) {
            return false;
        }
    }
    
    return true;
}
 
int main() {
    cu::runOverMultipleTestsInput([](const int testId) {
        int N = cu::read<int>();
        vector<int> A = cu::readArray<int>(N);
        vector<int> B = cu::readArray<int>(N);
        
        if(isSinglePushPossible(A, B)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    });
    return 0;
}
