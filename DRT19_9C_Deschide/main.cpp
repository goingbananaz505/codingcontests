#include <iostream>
#include <vector>
#include <algorithm>

struct segment {
    int left;
    int right;
    segment() : segment(0, 0) { }
    segment(int left, int right) : left(left), right(right) { }
};
using slide = segment;

class Solution {
public:
    std::vector<int> getSmallestIntersects(const std::vector<segment>& segments,
                                           const std::vector<slide>& slides) const {
        std::vector<int> lefts = getLeftBounds(segments);
        std::vector<int> rights = getRightBounds(segments);
        std::sort(lefts.begin(), lefts.end());
        std::sort(rights.begin(), rights.end());
        
        return getSmallestIntersects(lefts, rights, slides);
    }
private:
    std::vector<int> getLeftBounds(const std::vector<segment>& segments) const {
        std::vector<int> lefts(segments.size());
        for(int i = 0; i < segments.size(); i++) {
            lefts[i] = segments[i].left;
        }
        return lefts;
    }
    std::vector<int> getRightBounds(const std::vector<segment>& segments) const {
        std::vector<int> rights(segments.size());
        for(int i = 0; i < segments.size(); i++) {
            rights[i] = segments[i].right;
        }
        return rights;
    }
    
    std::vector<int> getSmallestIntersects(const std::vector<int>& lefts,
                                           const std::vector<int>& rights,
                                           const std::vector<slide>& slides) const {
        std::vector<int> intersects(slides.size());
        for(int i = 0; i < slides.size(); i++) {
            intersects[i] = getSmallestIntersectInSlide(lefts, rights, slides[i]);
        }
        return intersects;
    }
    int getSmallestIntersectInSlide(const std::vector<int>& lefts,
                                    const std::vector<int>& rights,
                                    const slide& slide) const {
        int left = getSmallestRightBoundLargerThan(rights, slide.left);
        int right = getLargestLeftBoundSmallerThan(lefts, slide.right);
        
        if(left >= right) {
            return 0;
        }
        return right - left;
    }
    int getSmallestRightBoundLargerThan(const std::vector<int>& rights,
                                        const int slideLeft) const {
        return *std::lower_bound(rights.begin(), rights.end(), slideLeft);
    }
    int getLargestLeftBoundSmallerThan(const std::vector<int>& lefts,
                                        const int slideRight) const {
        return *(std::lower_bound(lefts.begin(), lefts.end(), slideRight) - 1);
    }
};

#include <functional>

namespace consoleutils {

template <typename T>
T read() {
    T value;
    std::cin >> value;
    return value;
}

template <typename T>
std::vector<T> readArray(int size) {
    std::vector<T> result(size);
    for(int i = 0; i < size; i++) {
        std::cin >> result[i];
    }
    return result;
}

template <typename T>
std::vector<T> readSizeAndArray() {
    int size = read<int>();
    return readArray<T>(size);
}

void runOverMultipleTestsInput(std::function<void(const int)> runTest) {
    int testsCount = read<int>();
    for(int i = 0; i < testsCount; i++) {
        runTest(i);
    }
}

}

Solution s;
int main() {
    using namespace std;
    namespace cu = consoleutils;
    
    const int N = cu::read<int>();
    const int Q = cu::read<int>();
    vector<segment> segments(N);
    for(int i = 0; i < N; i++) {
        segments[i] = segment(cu::read<int>(), cu::read<int>());
    }
    vector<slide> slides(Q);
    for(int i = 0; i < Q; i++) {
        slides[i] = slide(cu::read<int>(), cu::read<int>());
    }
    
    vector<int> intersects = s.getSmallestIntersects(segments, slides);
    for(const int intersect : intersects) {
        cout << intersect << '\n';
    }
    return 0;
}
