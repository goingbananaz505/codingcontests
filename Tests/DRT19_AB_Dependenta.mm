#import <XCTest/XCTest.h>
#include <vector>

#include "../DRT19_AB_Dependenta/solution.h"

@interface DRT19_AB_Dependenta : XCTestCase

@end

@implementation DRT19_AB_Dependenta

- (void)testSmoke1 {
    const std::vector<int> coffeeCost = { 4, 10, 6, 2, 6, 2, 5 };
    Solution s;
    XCTAssertEqual(17, s.getCoffeeCost(2, 4, coffeeCost));
    
}

- (void)testSmoke2 {
    const std::vector<int> coffeeCost = { 6, 19, 3, 4, 4, 2, 6, 7, 8 };
    const std::vector<int> expected = { 2, 5, 11, 18, 30, 43, 62, 83, 121 };
    Solution s;
    for(int i = 0; i < expected.size(); i++) {
        int K = i + 1;
        XCTAssertEqual(expected[i], s.getCoffeeCost(2, K, coffeeCost));
    }
}

@end
