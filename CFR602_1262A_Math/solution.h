#ifndef solution_h
#define solution_h

#include <vector>
#include <utility>

class Solution {
public:
    int getLengthOfSegmentIntersectingAll(const std::vector<std::pair<int, int>>& segments) const {
        int left = getSmallestRightBound(segments);
        int right = getLargestLeftBound(segments);
        
        if(left >= right) {
            return 0;
        }
        return right - left;
    }
private:
    int getLargestLeftBound(const std::vector<std::pair<int, int>>& segments) const {
        int best = segments[0].first;
        for(const auto& seg : segments) {
            int left = seg.first;
            if(left > best) {
                best = left;
            }
        }
        return best;
    }
    int getSmallestRightBound(const std::vector<std::pair<int, int>>& segments) const {
        int best = segments[0].second;
        for(const auto& seg : segments) {
            int right = seg.second;
            if(right < best) {
                best = right;
            }
        }
        return best;
    }
};

#endif
