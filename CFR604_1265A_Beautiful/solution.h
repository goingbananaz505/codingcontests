#ifndef solution_h
#define solution_h

class Solution {
public:
    bool isBeautifulStringPossible(const std::string& word, std::string* beautifulString) const {
        bool isPossible = this->isPossible(word);
        if(isPossible) {
            buildBeautifulString(word, beautifulString);
        }
        
        return isPossible;
    }
private:
    bool isPossible(const std::string& word) const {
        for(int i = 1; i < word.size(); i++) {
            if(word[i - 1] == word[i] && word[i] != '?') {
                return false;
            }
        }
        return true;
    }
    
    void buildBeautifulString(const std::string& word, std::string* beautifulString) const {
        beautifulString->resize(word.size());
        for(int i = 0; i < word.size(); i++) {
            if(word[i] != '?') {
                (*beautifulString)[i] = word[i];
            } else {
                (*beautifulString)[i] = findMissingCharacter(beautifulString, i, word);
            }
        }
    }
    char findMissingCharacter(std::string *beautifulString, int i, const std::string &word) const {
        char missing = ' ';
        for(char c = 'a'; c <= 'c'; c++) {
            bool violeatesLeft = ((i > 0) && (*beautifulString)[i - 1] == c);
            bool violeatesRight = ((i < word.size() - 1) && c == word[i + 1]);
            if(!violeatesLeft && !violeatesRight) {
                missing = c;
                break;
            }
        }
        return missing;
    }
};

#endif
