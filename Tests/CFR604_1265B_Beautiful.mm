#import <XCTest/XCTest.h>
#include <vector>
#include <string>

#include "../CFR604_1265B_Beautiful/solution.h"

@interface CFR604_1265B_Beautiful : XCTestCase

@end

@implementation CFR604_1265B_Beautiful

- (void)testSmoke1 {
    Solution s;
    std::vector<int> p = { 4, 5, 1, 3, 2, 6 };
    XCTAssertEqual(s.getBeautifulNumbersString(p), "101011");
}

- (void)testSmoke2 {
    Solution s;
    std::vector<int> p = { 5, 3, 1, 2, 4 };
    XCTAssertEqual(s.getBeautifulNumbersString(p), "11111");
}

- (void)testSmoke3 {
    Solution s;
    std::vector<int> p = { 1, 4, 3, 2 };
    XCTAssertEqual(s.getBeautifulNumbersString(p), "1001");
}

@end
