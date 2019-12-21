#import <XCTest/XCTest.h>
#include <vector>
#include <string>

#include "../CFR609_1269A_Equation/solution.h"

@interface CFR609_1269A_Equation : XCTestCase

@end

@implementation CFR609_1269A_Equation

- (void)testSmoke {
    Solution s;
    XCTAssertEqual(std::make_pair(9, 8),
                   s.getCompositeNumbersPairWithSubstractionOfValue(1));
    XCTAssertEqual(std::make_pair(4608, 4096),
                   s.getCompositeNumbersPairWithSubstractionOfValue(512));
}

@end
