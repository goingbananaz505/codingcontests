#ifndef solution_h
#define solution_h

class Solution {
public:
    std::string getBeautifulNumberGreaterThan(const std::string& x,
                                              const int k) const {
        std::string pattern = getFirstDigits(x, k);
        std::string candidate = getNumberFromPattern(pattern, static_cast<int>(x.size()));
        if(candidate < x) {
            addOne(pattern);
            candidate = getNumberFromPattern(pattern, static_cast<int>(x.size()));
        }
        return candidate;
    }
private:
    std::string getFirstDigits(const std::string& x, const int k) const {
        return x.substr(0, k);
    }
    std::string getNumberFromPattern(const std::string& pattern, const int size) const {
        std::string number;
        int indexInPattern = 0;
        for(int i = 0; i < size; i++) {
            number += pattern[indexInPattern];
            indexInPattern = (indexInPattern + 1) % pattern.size();
        }
        return number;
    }
    void addOne(std::string& number) const {
        int index = static_cast<int>(number.size() - 1);
        
        int remainder = 0;
        do {
            int additionResult = charToDigit(number[index]) + 1;
            remainder = (additionResult) / 10;
            number[index] = digitToChar(additionResult % 10);
            index--;
        } while(remainder != 0 && index >= 0);
        
        if(remainder != 0) {
            number = "1" + number;
        }
    }
    int charToDigit(const char c) const {
        return c - '0';
    }
    int digitToChar(const int digit) const {
        return (char)(digit + '0');
    }
};

#endif
