#import <XCTest/XCTest.h>

#include "../LCW120_979_Distribute/solution.h"
#include <vector>

@interface LCW120_979_Distribute : XCTestCase

@end

@implementation LCW120_979_Distribute

- (void)testSmoke1 {
    Solution s;
    TreeNode root(3);
    TreeNode left(0);
    TreeNode right(0);
    root.left = &left;
    root.right = &right;
    XCTAssert(s.distributeCoins(&root) == 2);
}

- (void)testSmoke2 {
    Solution s;
    TreeNode root(0);
    TreeNode left(3);
    TreeNode right(0);
    root.left = &left;
    root.right = &right;
    XCTAssert(s.distributeCoins(&root) == 3);
}

- (void)testSmoke3 {
    Solution s;
    TreeNode root(1);
    TreeNode left(0);
    TreeNode right(2);
    root.left = &left;
    root.right = &right;
    XCTAssert(s.distributeCoins(&root) == 2);
}

- (void)testSmoke4 {
    Solution s;
    TreeNode root(1);
    TreeNode left(0);
    TreeNode right(0);
    TreeNode rightsLeft(3);
    root.left = &left;
    root.right = &right;
    root.left->right = &rightsLeft;
    XCTAssert(s.distributeCoins(&root) == 4);
}

- (void)testBase {
    XCTAssert(true);
}

- (void)testEdgeOneNode {
    Solution s;
    TreeNode root(1);
    XCTAssert(s.distributeCoins(&root) == 0);
}

- (void)testEdgeOnlyLeftNodes {
    Solution s;
    TreeNode root(0);
    TreeNode left(0);
    TreeNode leftleft(3);
    root.left = &left;
    root.left->left = &leftleft;
    XCTAssert(s.distributeCoins(&root) == 3);
}

- (void)testEdgeOnlyRightNodes {
    Solution s;
    TreeNode root(0);
    TreeNode right(0);
    TreeNode rightright(3);
    root.right = &right;
    root.right->right = &rightright;
    XCTAssert(s.distributeCoins(&root) == 3);
}

- (void)testEdgeAllNodesToLeft {
    Solution s;
    std::vector<TreeNode*> nodes;
    
    auto root = new TreeNode(100);
    nodes.emplace_back(root);
    for(int i = 1; i < 100; i++) {
        nodes.emplace_back(new TreeNode(0));
        nodes[i - 1]->left = nodes[i];
    }
    XCTAssert(s.distributeCoins(root) == 100 * 99 / 2);
    
    for(int i = 0; i < 100; i++) {
        delete nodes[i];
    }
}

- (void)testEdgeAllNodesToRight {
    Solution s;
    std::vector<TreeNode*> nodes;
    
    auto root = new TreeNode(100);
    nodes.emplace_back(root);
    for(int i = 1; i < 100; i++) {
        nodes.emplace_back(new TreeNode(0));
        nodes[i - 1]->right = nodes[i];
    }
    XCTAssert(s.distributeCoins(root) == 100 * 99 / 2);
    
    for(int i = 0; i < 100; i++) {
        delete nodes[i];
    }
}

@end
