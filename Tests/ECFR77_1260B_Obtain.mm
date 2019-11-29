#import <XCTest/XCTest.h>

#include "../ECFR77_1260B_Obtain/solution.h"

@interface ECFR77_1260B_Obtain : XCTestCase

@end

@implementation ECFR77_1260B_Obtain

- (void)testSmokes {
    Solution s;
    XCTAssert(s.canBeEqualSimultaneously(6, 9));
    XCTAssert(!s.canBeEqualSimultaneously(1, 1));
    XCTAssert(s.canBeEqualSimultaneously(1, 2));
}

- (void)testBase {
    Solution s;
    XCTAssert(s.canBeEqualSimultaneously(6, 9));
    XCTAssert(s.canBeEqualSimultaneously(5, 7));
    XCTAssert(s.canBeEqualSimultaneously(4, 5));
    XCTAssert(s.canBeEqualSimultaneously(3, 3));
    XCTAssert(s.canBeEqualSimultaneously(2, 1));
    XCTAssert(!s.canBeEqualSimultaneously(7, 3));
    XCTAssert(s.canBeEqualSimultaneously(6, 3));
    XCTAssert(!s.canBeEqualSimultaneously(5, 3));
    XCTAssert(!s.canBeEqualSimultaneously(4, 3));
    XCTAssert(!s.canBeEqualSimultaneously(2, 3));
    XCTAssert(!s.canBeEqualSimultaneously(12, 17));
    XCTAssert(!s.canBeEqualSimultaneously(11, 17));
    XCTAssert(!s.canBeEqualSimultaneously(2, 17));
}

- (void)testEdge {
    Solution s;
    XCTAssert(s.canBeEqualSimultaneously(0, 0));
    XCTAssert(!s.canBeEqualSimultaneously(0, 1));
    XCTAssert(!s.canBeEqualSimultaneously(0, 2));
    XCTAssert(!s.canBeEqualSimultaneously(0, 3));
    XCTAssert(!s.canBeEqualSimultaneously(1, 1));
    XCTAssert(s.canBeEqualSimultaneously(1, 2));
    XCTAssert(!s.canBeEqualSimultaneously(1, 3));
    XCTAssert(!s.canBeEqualSimultaneously(1000000000, 1000000000));
    XCTAssert(!s.canBeEqualSimultaneously(1000000000, 1000000000 - 1));
    XCTAssert(s.canBeEqualSimultaneously(1000000000, 1000000000 - 2));
    XCTAssert(!s.canBeEqualSimultaneously(1000000000, 1000000000 - 3));
    XCTAssert(!s.canBeEqualSimultaneously(1000000000 - 1, 1000000000));
    XCTAssert(s.canBeEqualSimultaneously(1000000000 - 2, 1000000000));
    XCTAssert(!s.canBeEqualSimultaneously(1000000000 - 3, 1000000000));
    XCTAssert(!s.canBeEqualSimultaneously(1000000000, 0));
    XCTAssert(!s.canBeEqualSimultaneously(1000000000, 1));
    XCTAssert(!s.canBeEqualSimultaneously(0, 1000000000));
    XCTAssert(!s.canBeEqualSimultaneously(1, 1000000000));
}

@end
