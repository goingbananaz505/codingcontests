#import <XCTest/XCTest.h>

#include "../ECFR77_1260C_Infinite/solution.h"

@interface ECFR77_1260C_Infinite : XCTestCase

@end

@implementation ECFR77_1260C_Infinite

- (void)testSmokes {
    Solution s;
    XCTAssert(s.isExecutionAvoidable(1, 1, 2));
    XCTAssert(!s.isExecutionAvoidable(2, 10, 4));
    XCTAssert(s.isExecutionAvoidable(5, 2, 3));
    XCTAssert(s.isExecutionAvoidable(3, 2, 2));
}

- (void)testBase {
    Solution s;
    XCTAssert(s.isExecutionAvoidable(2, 3, 2));
    XCTAssert(s.isExecutionAvoidable(2, 3, 3));
    XCTAssert(!s.isExecutionAvoidable(5, 3, 2));
    XCTAssert(s.isExecutionAvoidable(5, 3, 3));
}

- (void)testEdge {
    Solution s;
    XCTAssert(s.isExecutionAvoidable(1, 1, 2));
    XCTAssert(s.isExecutionAvoidable(1000000000, 1000000000, 2));
    XCTAssert(s.isExecutionAvoidable(1000000000, 1000000000, 1000000000));
    XCTAssert(s.isExecutionAvoidable(1000000000 - 1, 1000000000, 1000000000));
    XCTAssert(s.isExecutionAvoidable(1000000000 - 1, 1000000000, 1000000000 - 1));
}

@end
