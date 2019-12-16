#ifndef solution_h
#define solution_h

#include <vector>

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
        for(const int& right : rights) {
            if(right >= slideLeft) {
                return right;
            }
        }
        return -1;
    }
    int getLargestLeftBoundSmallerThan(const std::vector<int>& lefts,
                                        const int slideRight) const {
        for(int i = static_cast<int>(lefts.size()) - 1; i >= 0; i--) {
            const int& left = lefts[i];
            if(left <= slideRight) {
                return left;
            }
        }
        return -1;
    }
};

#endif
