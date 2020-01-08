#import <XCTest/XCTest.h>
#include <vector>
#include <string>

#include "../CFR604_1265A_Beautiful/solution.h"

@interface CFR604_1265A_Beautiful : XCTestCase

@end

@implementation CFR604_1265A_Beautiful

- (void)testSmoke1 {
    Solution s;
    std::string beautiful;
    bool isPossibleActual = s.isBeautifulStringPossible("a???cb", &beautiful);
    XCTAssert(isPossibleActual);
    XCTAssertEqual(beautiful, "ababcb");
}

- (void)testSmoke2 {
    Solution s;
    std::string beautiful;
    bool isPossibleActual = s.isBeautifulStringPossible("a??bbc", &beautiful);
    XCTAssert(!isPossibleActual);
    XCTAssertEqual(beautiful, "");
}

- (void)testSmoke3 {
    Solution s;
    std::string beautiful;
    bool isPossibleActual = s.isBeautifulStringPossible("a?b?c", &beautiful);
    XCTAssert(isPossibleActual);
    XCTAssertEqual(beautiful, "acbac");
}

@end
