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
    bool isExecutionAvoidable(const int first, const int second, const int maxInRow) const {
        int long long a = first;
        int long long b = second;
        if(a > b) { swap(a, b); }
        int long long k = maxInRow;
        
        auto _lcm = lcm(a, b);
        auto ra = _lcm / a;
        auto rb = _lcm / b;
        
        int long long w = (ra - 1) / rb;
        int long long e = (ra - 1) % rb;
        if(e != 0) {
            w++;
        }
        
        return (w >= k);
    }
private:
    int long long gcd(int long long a, int long long b) const {
        int long long r = a % b;
        while(r != 0) {
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }
    int long long lcm(int long long a, int long long b) const {
        return a * b / gcd(a, b);
    }
};

int main() {
    namespace cu = consoleutils;

    Solution solution;
    cu::runOverMultipleTestsInput([&](const int testId) {
        int a = cu::read<int>();
        int b = cu::read<int>();
        int k = cu::read<int>();
        
        if(solution.isExecutionAvoidable(a, b, k)) {
            cout << "OBEY" << '\n';
        } else {
            cout << "REBEL" << '\n';
        }
    });
    return 0;
}
