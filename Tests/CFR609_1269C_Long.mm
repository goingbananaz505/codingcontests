#import <XCTest/XCTest.h>
#include <vector>
#include <string>

#include "../CFR609_1269C_Long/solution.h"

@interface CFR609_1269C_Long : XCTestCase

@end

@implementation CFR609_1269C_Long

- (void)testSmoke {
    Solution s;
    XCTAssertEqual("353", s.getBeautifulNumberGreaterThan("353", 2));
    XCTAssertEqual("1313", s.getBeautifulNumberGreaterThan("1234", 2));
}

- (void)testBase {
    Solution s;
    XCTAssertEqual("131313", s.getBeautifulNumberGreaterThan("123456", 2));
    XCTAssertEqual("656565", s.getBeautifulNumberGreaterThan("654321", 2));
    XCTAssertEqual("666666", s.getBeautifulNumberGreaterThan("654321", 1));
    XCTAssertEqual("124124", s.getBeautifulNumberGreaterThan("123456", 3));
    XCTAssertEqual("13131", s.getBeautifulNumberGreaterThan("12345", 2));
    XCTAssertEqual("54545", s.getBeautifulNumberGreaterThan("54321", 2));
}

- (void)testEdge {
    Solution s;
    XCTAssertEqual("444", s.getBeautifulNumberGreaterThan("353", 1));
    XCTAssertEqual("66666", s.getBeautifulNumberGreaterThan("59921", 1));
    XCTAssertEqual("60606", s.getBeautifulNumberGreaterThan("59921", 2));
    XCTAssertEqual("59959", s.getBeautifulNumberGreaterThan("59921", 3));
    XCTAssertEqual("12312312", s.getBeautifulNumberGreaterThan("12312312", 3));
    XCTAssertEqual("12412412", s.getBeautifulNumberGreaterThan("12312313", 3));
    XCTAssertEqual("9", s.getBeautifulNumberGreaterThan("9", 1));
    XCTAssertEqual("99", s.getBeautifulNumberGreaterThan("99", 1));
    XCTAssertEqual("99", s.getBeautifulNumberGreaterThan("99", 2));
    XCTAssertEqual("98", s.getBeautifulNumberGreaterThan("98", 2));
    XCTAssertEqual("999", s.getBeautifulNumberGreaterThan("998", 2));
    XCTAssertEqual("999", s.getBeautifulNumberGreaterThan("992", 2));
}

@end
