#import <XCTest/XCTest.h>

#include "../DRT19_9C_Deschide/solution.h"

@interface DRT19_9C_Deschide : XCTestCase

@end

@implementation DRT19_9C_Deschide

- (void)evaluateTest: (std::vector<segment>)segments : (std::vector<slide>)slides : (std::vector<int>)expected {
    Solution s;
    std::vector<int> actual = s.getSmallestIntersects(segments, slides);
    XCTAssertEqual(actual.size(), expected.size());
    
    if(actual.size() == expected.size()) {
        for(int i = 0; i < expected.size(); i++) {
            XCTAssertEqual(actual[i], expected[i]);
        }
    }
}

- (void)testSmokes {
    std::vector<segment> segments = {
        segment(1, 2),
        segment(3, 4),
        segment(3, 6),
        segment(8, 12),
    };
    std::vector<slide> slides = {
        slide(1, 6),
        slide(8, 13)
    };
    std::vector<int> expected = { 1, 0 };
    
    [self evaluateTest: segments : slides : expected];
}

- (void)testBase1 {
    std::vector<segment> segments = {
        segment(4, 5),
        segment(5, 9),
        segment(7, 7),
        segment(111, 119),
        segment(104, 117),
        segment(116, 116),
        segment(103, 112),
        segment(114, 117),
        segment(201, 210),
        segment(301, 301),
    };
    std::vector<slide> slides = {
        slide(0, 100),
        slide(100, 200),
        slide(200, 300),
        slide(300, 400),
    };
    std::vector<int> expected = { 2, 4, 0, 0 };
    
    [self evaluateTest: segments : slides : expected];
}

- (void)testEdge1 {
    std::vector<segment> segments = {
        segment(999999999, 999999999),
        segment(999999999, 999999999),
        segment(999999997, 999999998),
        segment(99999997, 99999998),
        segment(99999999, 99999999),
    };
    std::vector<slide> slides = {
        slide(999999998, 1000000000),
        slide(999999998, 1000000000),
        slide(999999997, 999999998),
        slide(100000001, 1000000000),
        slide(0, 100000000)
    };
    std::vector<int> expected = { 1, 1, 0, 1, 1 };
    
    [self evaluateTest: segments : slides : expected];
}


@end
