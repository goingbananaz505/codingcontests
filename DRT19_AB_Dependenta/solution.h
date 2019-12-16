#ifndef solution_h
#define solution_h

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

#endif
