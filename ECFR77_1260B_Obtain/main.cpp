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
#include <algorithm>

using namespace std;

class Solution {
public:
    bool solve(int a, int b) const {
        if(a > b) {
            swap(a, b);
        }
        
        int areGoingToBeEqualAt = a - (b - a);
        if(areGoingToBeEqualAt < 0) {
            return false;
        }
        
        return (areGoingToBeEqualAt % 3 == 0);
    }
};

int main() {
    namespace cu = consoleutils;

    Solution solution;
    cu::runOverMultipleTestsInput([&](const int testId) {
        int a = cu::read<int>();
        int b = cu::read<int>();
        
        if(solution.solve(a, b)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    });
    return 0;
}
