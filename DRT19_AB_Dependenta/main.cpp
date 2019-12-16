#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int long long getCoffeeCost(const int M, const int K,
                                const std::vector<int>& C) const {
        auto coffeeCost = C;
        std::sort(coffeeCost.begin(), coffeeCost.end());
        
        std::vector<int long long> A(coffeeCost.size());
        for(int i = 0; i < coffeeCost.size(); i++) {
            A[i] = coffeeCost[i];
            if(i > 0) {
                A[i] += A[i - 1];
            }
        }
        
        std::vector<int long long> B(K);
        for(int i = 0; i < K; i++) {
            B[i] = A[i];
            if(i >= M) {
                B[i] += B[i - M];
            }
        }
        
        return B[K - 1];
    }
};

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

Solution s;
int main() {
    using namespace std;
    namespace cu = consoleutils;
    
    const int N = cu::read<int>();
    const int M = cu::read<int>();
    const int K = cu::read<int>();
    vector<int> C = cu::readArray<int>(N);
    
    cout << s.getCoffeeCost(M, K, C);
    
    return 0;
}
