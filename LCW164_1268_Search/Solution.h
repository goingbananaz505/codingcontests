#ifndef Solution_h
#define Solution_h

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> suggestedProducts(const std::vector<std::string>& products,
                                                            const std::string& searchWord) {
        TrieNode* trie = buildTrieFromDictionary(products);
        return getMaximumThreeSuggestions(trie, searchWord);
    }
private:
    static const int ALPHABET_SIZE = 26;
    struct TrieNode {
        struct TrieNode *children[ALPHABET_SIZE];
        int wordsEndingHere;
    };
    
    TrieNode* getNode() const {
        struct TrieNode *pNode = new TrieNode;
      
        pNode->wordsEndingHere = 0;
      
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = nullptr;
      
        return pNode;
    }
    void insert(TrieNode* root, const std::string& key) const {
        TrieNode *pCrawl = root;
      
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();
      
            pCrawl = pCrawl->children[index];
        }

        pCrawl->wordsEndingHere++;
    }
    
    TrieNode* buildTrieFromDictionary(const std::vector<std::string>& keys) const {
        TrieNode* root = getNode();
        for (int i = 0; i < keys.size(); i++)
            this->insert(root, keys[i]);
        return root;
    }
    
    std::vector<std::vector<std::string>> getMaximumThreeSuggestions(TrieNode* root,
                                                                    const std::string& word) const {
        std::vector<std::vector<std::string>> result(word.size());
        
        TrieNode* pCrawl = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(pCrawl->children[index] != nullptr) {
                pCrawl = pCrawl->children[index];
                result[i] = getMaxThreeFromNode(pCrawl, word.substr(0, i + 1));
            } else {
                break;
            }
        }
        
        return result;
    }
    
    std::vector<std::string> getMaxThreeFromNode(const TrieNode* node, const std::string& word) const {
        std::vector<std::string> result;
        dfs(node, word, result);
        
        return result;
    }
    
    void dfs(const TrieNode* node, const std::string& partial, std::vector<std::string>& result) const {
        if(result.size() >= 3) {
            return;
        }
        if(node->wordsEndingHere != 0) {
            for(int i = 0; i < node->wordsEndingHere; i++) {
                result.emplace_back(partial);
                if(result.size() >= 3) {
                    return;
                }
            }
        }
        if(result.size() >= 3) {
            return;
        }
        
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if(node->children[i] != nullptr) {
                dfs(node->children[i], partial + (char)('a' + i), result);
                if(result.size() >= 3) {
                    return;
                }
            }
        }
    }
};

#endif
