#ifndef solution_h
#define solution_h

template<typename T>
using matrix = std::vector<std::vector<T>>;

class Solution {
public:
    matrix<int> shiftGrid(matrix<int> grid, const int k) const {
        for(int i = 0; i < k; i++) {
            shiftColumnsToTheRight(grid);
            pushFirstColumnDown(grid);
        }
        return grid;
    }
private:
    void shiftColumnsToTheRight(matrix<int>& grid) const {
        std::vector<int> lastColumn = getLastColumn(grid);
        for(int j = static_cast<int>(grid[0].size()) - 1; j >= 1; j--) {
            copyColumn(grid, j, j - 1);
        }
        setFirstColumn(grid, lastColumn);
    }
    std::vector<int> getLastColumn(const matrix<int>& grid) const {
        std::vector<int> col(grid.size());
        for(int i = 0; i < grid.size(); i++) {
            col[i] = grid[i][grid[0].size() - 1];
        }
        return col;
    }
    void copyColumn(matrix<int>& grid, int destinationIndex, int sourceIndex) const {
        for(int i = 0; i < grid.size(); i++) {
            grid[i][destinationIndex] = grid[i][sourceIndex];
        }
    }
    void setFirstColumn(matrix<int>& grid, const std::vector<int> column) const {
        for(int i = 0; i < grid.size(); i++) {
            grid[i][0] = column[i];
        }
    }
    
    void pushFirstColumnDown(matrix<int>& grid) const {
        int firstColumnLastElement = grid[grid.size() - 1][0];
        for(int i = static_cast<int>(grid.size()) - 1; i >= 1; i--) {
            grid[i][0] = grid[i - 1][0];
        }
        grid[0][0] = firstColumnLastElement;
    }
};

#endif
