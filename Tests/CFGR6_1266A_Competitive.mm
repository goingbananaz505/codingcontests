#import <XCTest/XCTest.h>
#include <vector>
#include <string>

#include "../CFGR6_1266A_Competitive/solution.h"

@interface CFGR6_1266A_Competitive : XCTestCase

@end

@implementation CFGR6_1266A_Competitive

- (void)testSmoke {
    Solution s;
    XCTAssert(s.isPossibleRearrangeDivisibleBySixty("603"));
    XCTAssert(s.isPossibleRearrangeDivisibleBySixty("006"));
    XCTAssert(!s.isPossibleRearrangeDivisibleBySixty("205"));
    XCTAssert(!s.isPossibleRearrangeDivisibleBySixty("228"));
    XCTAssert(!s.isPossibleRearrangeDivisibleBySixty("1053"));
    XCTAssert(s.isPossibleRearrangeDivisibleBySixty("0000000000000000000000000000000000000000000000"));
}

@end
