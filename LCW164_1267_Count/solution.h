#ifndef solution_h
#define solution_h

#include <vector>
#include "../Utils/datautils.h"

namespace du = datautils;

class Solution {
public:
    int countServers(const du::matrix<int>& grid) const {
        std::vector<int> sumOnLines = getSumOnLines(grid);
        std::vector<int> sumOnColumns = getSumOnColumns(grid);
        return getCellsCountWithBothSumsOne(grid, sumOnLines, sumOnColumns);
    }
private:
    std::vector<int> getSumOnLines(const du::matrix<int>& grid) const {
        std::vector<int> sum(grid.size(), 0);
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                sum[i] += grid[i][j];
            }
        }
        return sum;
    }
    std::vector<int> getSumOnColumns(const du::matrix<int>& grid) const {
        std::vector<int> sum(grid[0].size(), 0);
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                sum[j] += grid[i][j];
            }
        }
        return sum;
    }
    int getCellsCountWithBothSumsOne(const du::matrix<int>& grid,
                                     const std::vector<int> sumOnLines,
                                     const std::vector<int> sumOnColumns) const {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1 && (sumOnLines[i] != 1 || sumOnColumns[j] != 1)) {
                    count++;
                }
            }
        }
        return count;
    }
};

#endif
