#import <XCTest/XCTest.h>
#include <vector>
#include <string>

#include "../CFGR6_1266C_Diverse/solution.h"

#include "../Utils/datautils.h"
namespace du = datautils;

@interface CFGR6_1266C_Diverse : XCTestCase

@end

@implementation CFGR6_1266C_Diverse

- (void)testSmoke1 {
    Solution s;
    du::matrix<int> m;
    XCTAssert(s.isDiverseMatrixPossible(2, 2, m));
    XCTAssertEqual(m[0][0], 3);
    XCTAssertEqual(m[0][1], 6);
    XCTAssertEqual(m[1][0], 4);
    XCTAssertEqual(m[1][1], 8);
}

- (void)testSmoke2 {
    Solution s;
    du::matrix<int> m;
    XCTAssert(!s.isDiverseMatrixPossible(1, 1, m));
}

@end
