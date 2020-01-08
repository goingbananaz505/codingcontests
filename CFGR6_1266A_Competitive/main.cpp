#include <iostream>
#include <string>
#include <vector>
#include "../Utils/consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;

Solution solution;
int main() {
    cu::runOverMultipleTestsInput([](const int testId) {
        string number = cu::read<string>();
        bool isPossible = solution.isPossibleRearrangeDivisibleBySixty(number);
        if(isPossible) {
            cout << "red" << '\n';
        } else {
            cout << "cyan" << '\n';
        }
    });
}
