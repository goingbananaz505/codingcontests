#include <iostream>
#include "solution.h"

int main() {
    using namespace std;
    Solution s;
    TreeNode root(3);
    TreeNode left(0);
    TreeNode right(0);
    root.left = &left;
    root.right = &root;
    
    cout << s.distributeCoins(&root) << endl;
}
