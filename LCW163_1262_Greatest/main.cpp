#include <iostream>
#include "solution.h"

using namespace std;
Solution s;

int main() {
    vector<int> numbers = { 3, 6, 5, 1, 8 };
    cout << s.maxSumDivThree(numbers) << endl;
    return 0;
}
