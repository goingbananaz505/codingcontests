#ifndef solution_h
#define solution_h

class Solution {
public:
    bool isExecutionAvoidable(const int first, const int second, const int maxInRow) const {
        int long long a = first;
        int long long b = second;
        if(a > b) { std::swap(a, b); }
        int long long k = maxInRow;
        
        auto _lcm = lcm(a, b);
        auto ra = _lcm / a;
        auto rb = _lcm / b;
        
        int long long w = (ra - 1) / rb;
        int long long e = (ra - 1) % rb;
        if(e != 0) {
            w++;
        }
        
        return (w < k);
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

#endif
