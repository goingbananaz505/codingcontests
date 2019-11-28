#import <XCTest/XCTest.h>

#include "../ECFR77_1260A_Heating/solution.h"

@interface ECFR77_1260A_Heating : XCTestCase

@end

@implementation ECFR77_1260A_Heating

- (void)testSmokes {
    Solution s;
    XCTAssert(s.getMinimumCost(1, 10000) == 100000000);
    XCTAssert(s.getMinimumCost(10000, 1) == 1);
    XCTAssert(s.getMinimumCost(2, 6) == 18);
    XCTAssert(s.getMinimumCost(4, 6) == 10);
}

- (void)testBase {
    Solution s;
    XCTAssert(s.getMinimumCost(3, 7) == 4 * 2 + 9);
    XCTAssert(s.getMinimumCost(3, 6) == 3 * (2 * 2));
    XCTAssert(s.getMinimumCost(3, 5) == 4 * 2 + 1);
    XCTAssert(s.getMinimumCost(1, 3) == 9);
}

- (void)testEdge {
    Solution s;
    XCTAssert(s.getMinimumCost(1, 7) == 7 * 7);
    XCTAssert(s.getMinimumCost(5, 1) == 1);
    XCTAssert(s.getMinimumCost(1, 1) == 1);
    XCTAssert(s.getMinimumCost(10000, 7) == 7);
    XCTAssert(s.getMinimumCost(5, 10000) == 20000000);
    XCTAssert(s.getMinimumCost(10000, 10000) == 10000);
}

@end
