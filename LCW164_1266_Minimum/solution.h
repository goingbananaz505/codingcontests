#ifndef solution_h
#define solution_h

class Solution {
public:
    int minTimeToVisitAllPoints(const std::vector<std::vector<int>>& points) const {
        int sum = 0;
        for(int i = 1; i < points.size(); i++) {
            sum += getTimeToVisitFromTo(points[i - 1], points[i]);
        }
        return sum;
    }
private:
    int getTimeToVisitFromTo(const std::vector<int>& p1, const std::vector<int>& p2) const {
        return std::max(abs(p2[0] - p1[0]), abs(p2[1] - p1[1]));
    }
};

#endif
