#ifndef solution_h
#define solution_h

#include "treenode.h"
#include <algorithm>

class Solution {
public:
    int distributeCoins(TreeNode* root) const {
        int cost = 0;
        equilibrateTree(root, &cost);
        return cost;
    }
private:
    void equilibrateTree(TreeNode* node, int* cost) const {
        int equilibrationCost = 0;
        equilibrateWithChildren(node, &equilibrationCost);
        *cost += equilibrationCost;
        
        if(node->left != nullptr) {
            int leftEquilibrationCost = 0;
            equilibrateTree(node->left, &leftEquilibrationCost);
            *cost += leftEquilibrationCost;
        }
        if(node->right != nullptr) {
            int rightEquilibrationCost = 0;
            equilibrateTree(node->right, &rightEquilibrationCost);
            *cost += rightEquilibrationCost;
        }
    }
    void equilibrateWithChildren(TreeNode* node, int* cost) const {
        int leftSurplus = getSurplus(node->left);
        int rightSurplus = getSurplus(node->right);
        
        if(node->left != nullptr) {
            node->left->val -= leftSurplus;
            node->val += leftSurplus;
        }
        if(node->right != nullptr) {
            node->right->val -= rightSurplus;
            node->val += rightSurplus;
        }
        
        *cost = abs(leftSurplus) + abs(rightSurplus);
    }
    int getSurplus(const TreeNode* node) const {
        int nodes = getNumberOfNodesInTree(node);
        int coins = getNumberOfCoinsInTree(node);
        return coins - nodes;
    }
    int getNumberOfNodesInTree(const TreeNode* node) const {
        if(node == nullptr) {
            return 0;
        }
        return 1 + getNumberOfNodesInTree(node->left) + getNumberOfNodesInTree(node->right);
    }
    int getNumberOfCoinsInTree(const TreeNode* node) const {
        if(node == nullptr) {
            return 0;
        }
        return node->val + getNumberOfCoinsInTree(node->left) + getNumberOfCoinsInTree(node->right);
    }
};

#endif
