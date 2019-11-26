#ifndef solution_h
#define solution_h

#include "treenode.h"
#include <unordered_set>

class FindElements {
public:
    FindElements(TreeNode* root) {
        initializeNodeValue(root, 0);
    }
    
    bool find(int target) {
        return elements.find(target) != elements.end();
    }
private:
    void initializeNodeValue(TreeNode* node, const int value) {
        node->val = value;
        elements.insert(value);
        if(node->left != nullptr) {
            initializeNodeValue(node->left, 2 * value + 1);
        }
        if(node->right != nullptr) {
            initializeNodeValue(node->right, 2 * value + 2);
        }
    }
    
    void printPreorder(const TreeNode* root) const {
        if(root->left != nullptr) {
            printPreorder(root->left);
        }
        if(root->right != nullptr) {
            printPreorder(root->right);
        }
    }
    
    std::unordered_set<int> elements;
};

#endif
