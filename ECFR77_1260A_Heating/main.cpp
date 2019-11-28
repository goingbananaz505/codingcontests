#include <iostream>
#include <vector>
#include <functional>

namespace consoleutils {

template <typename T>
T read() {
    T value;
    std::cin >> value;
    return value;
}

template <typename T>
std::vector<T> readArray(int size) {
    std::vector<T> result(size);
    for(int i = 0; i < size; i++) {
        std::cin >> result[i];
    }
    return result;
}

template <typename T>
std::vector<T> readSizeAndArray() {
    int size = read<int>();
    return readArray<T>(size);
}

void runOverMultipleTestsInput(std::function<void(const int)> runTest) {
    int testsCount = read<int>();
    for(int i = 0; i < testsCount; i++) {
        runTest(i);
    }
}

}

#include <string>

using namespace std;

class Solution {
public:
    int getMinimumCost(const int c, const int sum) const {
        int r = sum % c;
        int k = sum / c;
        
        if(r == 0) {
            return c * k * k;
        } else {
            return r * (k + 1) * (k + 1) + (c - r) * k * k;
        }
    }
};

int main() {
    namespace cu = consoleutils;

    Solution solution;
    cu::runOverMultipleTestsInput([&](const int testId) {
        int c = cu::read<int>();
        int sum = cu::read<int>();
        
        cout << solution.getMinimumCost(c, sum) << endl;
    });
    return 0;
}
