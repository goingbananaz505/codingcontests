#ifndef solution_h
#define solution_h

class Solution {
public:
    bool isPossibleRearrangeDivisibleBySixty(const std::string number) const {
        int sum = getDigitsSum(number);
        int zeros = getZeroDigitsCount(number);
        bool hasEvenNonZeroDigits = containsNonZeroEvenDigit(number);
        
        if(sum % 3 != 0) {
            return false;
        }
        if(zeros == 0) {
            return false;
        }
        if(zeros == 1 && !hasEvenNonZeroDigits) {
            return false;
        }
        return true;
    }
private:
    int getDigitsSum(const std::string& number) const {
        int sum = 0;
        for(const char& c : number) {
            sum += (c - '0');
        }
        return sum;
    }
    int getZeroDigitsCount(const std::string& number) const {
        int count = 0;
        for(const char& c : number) {
            if(c == '0') {
                count++;
            }
        }
        return count;
    }
    bool containsNonZeroEvenDigit(const std::string& number) const {
        for(const char& c : number) {
            int digit = c - '0';
            if(digit != 0 && digit % 2 == 0) {
                return true;
            }
        }
        return false;
    }
};

#endif
