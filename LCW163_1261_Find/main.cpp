#include <iostream>
#include "solution.h"
#include "treenode.h"

using namespace std;

int main() {
    TreeNode left(-1);
    TreeNode right(-1);
    TreeNode root(-1);
    root.left = &left;
    root.right = &right;
    
    FindElements obj(&root);
    
    for(int i = 0; i < 10; i++) {
        cout << obj.find(i) << endl;
    }
    
    return 0;
}
