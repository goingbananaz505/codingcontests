#ifndef treenode_h
#define treenode_h

namespace tree {
template<typename T>
struct TreeNode {
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>(T value) : val(value), left(nullptr), right(nullptr) {}
};

}
typedef tree::TreeNode<int> TreeNode;

#endif
