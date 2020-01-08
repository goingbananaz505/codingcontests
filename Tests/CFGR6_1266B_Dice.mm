#import <XCTest/XCTest.h>
#include <vector>
#include <string>

#include "../CFGR6_1266B_Dice/solution.h"

@interface CFGR6_1266B_Dice : XCTestCase

@end

@implementation CFGR6_1266B_Dice

- (void)testSmoke {
    Solution s;
    XCTAssertEqual(true, s.isPossibleBuildingDiceTower(29));
    XCTAssertEqual(true, s.isPossibleBuildingDiceTower(34));
    XCTAssertEqual(true, s.isPossibleBuildingDiceTower(19));
    XCTAssertEqual(false, s.isPossibleBuildingDiceTower(38));
}

- (void)testBase {
    Solution s;
    XCTAssertEqual(true, s.isPossibleBuildingDiceTower(15));
}

- (void)testEdge {
    Solution s;
    for(int i = 0; i <= 14; i++) {
        XCTAssertEqual(false, s.isPossibleBuildingDiceTower(i));
    }
}

@end
