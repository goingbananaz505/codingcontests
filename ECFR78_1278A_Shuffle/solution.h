#ifndef solution_h
#define solution_h
 
#include <algorithm>
#include <string>
 
class Solution {
public:
    bool isShuffleHashing(const std::string& password, const std::string& hash) const {
        int numberOfChecks = static_cast<int>(hash.size() - password.size()) + 1;
        std::string sortedPassword = getOrdered(password);
        for(int i = 0; i < numberOfChecks; i++) {
            bool isValid = isShuffleHashingFromIndex(i, hash, sortedPassword);
            if(isValid) {
                return true;
            }
        }
        return false;
    }
private:
    std::string getOrdered(const std::string& s) const {
        std::string t = s;
        sort(t.begin(), t.end());
        return t;
    }
    bool isShuffleHashingFromIndex(const int index, const std::string& hash, const std::string& sortedPassword) const {
        std::string t = hash.substr(index, sortedPassword.size());
        t = getOrdered(t);
        return t == sortedPassword;
    }
};
 
#endif
