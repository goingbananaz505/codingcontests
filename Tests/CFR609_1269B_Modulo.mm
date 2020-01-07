#import <XCTest/XCTest.h>
#include <vector>
#include <string>

#include "../CFR609_1269B_Modulo/solution.h"

@interface CFR609_1269B_Modulo : XCTestCase

@end

@implementation CFR609_1269B_Modulo

- (void)testSmoke1 {
    Solution s;
    std::vector<int> a = { 0, 0, 2, 1 };
    std::vector<int> b = { 2, 0, 1, 1 };
    XCTAssertEqual(1, s.getAdditionValueForModuloEquality(a, b, 3));
}

- (void)testSmoke2 {
    Solution s;
    std::vector<int> a = { 0, 0, 0 };
    std::vector<int> b = { 1, 1, 1 };
    XCTAssertEqual(1, s.getAdditionValueForModuloEquality(a, b, 3));
}

- (void)testSmoke3 {
    Solution s;
    std::vector<int> a = { 0, 0, 0, 2, 1 };
    std::vector<int> b = { 2, 1, 0, 0, 0 };
    XCTAssertEqual(0, s.getAdditionValueForModuloEquality(a, b, 3));
}

- (void)testSmoke4 {
    Solution s;
    std::vector<int> a = { 2, 0, 1, 1 };
    std::vector<int> b = { 0, 0, 2, 1 };
    XCTAssertEqual(2, s.getAdditionValueForModuloEquality(a, b, 3));
}

- (void)testSmoke5 {
    Solution s;
    std::vector<int> a = { 1, 1, 1, 0, 0, 0 };
    std::vector<int> b = { 2, 1, 2, 1, 1, 2 };
    XCTAssertEqual(1, s.getAdditionValueForModuloEquality(a, b, 3));
}

- (void)testSmoke6 {
    Solution s;
    std::vector<int> a = { 0, 0, 0, 1, 1, 1, 2, 2, 3 };
    std::vector<int> b = { 3, 3, 3, 0, 0, 0, 1, 1, 2 };
    XCTAssertEqual(3, s.getAdditionValueForModuloEquality(a, b, 4));
}

- (void)testSmoke7 {
    Solution s;
    std::vector<int> a = { 0, 0, 1, 1, 2, 3 };
    std::vector<int> b = { 3, 3, 0, 0, 1, 2 };
    XCTAssertEqual(3, s.getAdditionValueForModuloEquality(a, b, 4));
}

@end
