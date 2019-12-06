#ifndef solution_h
#define solution_h

#include "treenode.h"

class Solution {
public:
    int getPresentRedistributionCost(const std::vector<int>& preorder) const {
        TreeNode* root = deserializeTree(preorder);
        return getPresentRedistributionCost(root);
    }
    
private:
    TreeNode* deserializeTree(const std::vector<int>& preorder) const {
        int startIndex = 0;
        TreeNode* root = deserializeTree(preorder, startIndex);
        return root;
    }
    TreeNode* deserializeTree(const std::vector<int>& preorder, int& fromIndex) const {
        if(fromIndex < preorder.size()) {
            int value = preorder[fromIndex];
            if(value != -1) {
                TreeNode* node = new TreeNode(value);
                node->left = deserializeTree(preorder, ++fromIndex);
                node->right = deserializeTree(preorder, ++fromIndex);
                return node;
            }
        }
        
        return nullptr;
    }
    
    int getPresentRedistributionCost(TreeNode* root) const {
        int perHouse = getNumberOfPresentsInTree(root) / getNumberOfNodesInTree(root);
        int cost = 0;
        equilibrateTree(root, perHouse, &cost);
        return cost;
    }
    void equilibrateTree(TreeNode* node, const int presentsPerHouse, int* cost) const {
        int equilibrationCost = 0;
        equilibrateWithChildren(node, presentsPerHouse, &equilibrationCost);
        *cost += equilibrationCost;
        
        if(node->left != nullptr) {
            int leftEquilibrationCost = 0;
            equilibrateTree(node->left, presentsPerHouse, &leftEquilibrationCost);
            *cost += leftEquilibrationCost;
        }
        if(node->right != nullptr) {
            int rightEquilibrationCost = 0;
            equilibrateTree(node->right, presentsPerHouse, &rightEquilibrationCost);
            *cost += rightEquilibrationCost;
        }
    }
    void equilibrateWithChildren(TreeNode* node, const int presentsPerHouse,
                                 int* cost) const {
        int leftSurplus = getSurplus(node->left, presentsPerHouse);
        int rightSurplus = getSurplus(node->right, presentsPerHouse);
        
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
    int getSurplus(const TreeNode* node, const int presentsPerHouse) const {
        int nodes = getNumberOfNodesInTree(node);
        int presents = getNumberOfPresentsInTree(node);
        return presents - nodes * presentsPerHouse;
    }
    int getNumberOfNodesInTree(const TreeNode* node) const {
        if(node == nullptr) {
            return 0;
        }
        return 1 + getNumberOfNodesInTree(node->left) + getNumberOfNodesInTree(node->right);
    }
    int getNumberOfPresentsInTree(const TreeNode* node) const {
        if(node == nullptr) {
            return 0;
        }
        return node->val + getNumberOfPresentsInTree(node->left) + getNumberOfPresentsInTree(node->right);
    }
};

#endif
