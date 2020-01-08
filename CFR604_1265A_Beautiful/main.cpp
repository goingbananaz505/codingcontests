#include <iostream>
#include <vector>
#include <functional>
#include "../Utils/consoleutils.h"
#include "solution.h"

int main() {
    namespace cu = consoleutils;
    using namespace std;
 
    Solution solution;
    cu::runOverMultipleTestsInput([&](const int testId) {
        string word = cu::read<string>();
        string beautiful;
        bool isPossible = solution.isBeautifulStringPossible(word, &beautiful);
        
        if(isPossible) {
            cout << beautiful << '\n';
        } else {
            cout << "-1" << '\n';
        }
    });
    return 0;
}
