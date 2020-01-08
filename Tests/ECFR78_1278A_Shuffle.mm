#import <XCTest/XCTest.h>

#include "../ECFR78_1278A_Shuffle/solution.h"

@interface ECFR78_1278A_Shuffle : XCTestCase

@end

@implementation ECFR78_1278A_Shuffle

- (void)testSmokes {
    Solution s;
    XCTAssert(s.isShuffleHashing("abacaba", "zyxaabcaabkjh"));
    XCTAssert(s.isShuffleHashing("onetwothree", "threetwoone"));
    XCTAssert(!s.isShuffleHashing("one", "zzonneyy"));
    XCTAssert(s.isShuffleHashing("one", "none"));
    XCTAssert(!s.isShuffleHashing("twenty", "ten"));
}

@end
