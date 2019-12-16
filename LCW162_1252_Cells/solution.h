#ifndef solution_h
#define solution_h

#include "../Utils/datautils.h"

namespace du = datautils;

class Solution {
public:
    int oddCells(const int n, const int m, du::matrix<int>& indices) const {
        du::matrix<int> matrix(n, std::vector<int>(m, 0));
        incrementIndiciesInMatrix(matrix, n, m, indices);
        return countOddCells(matrix, n, m);
    }
private:
    void incrementIndiciesInMatrix(du::matrix<int>& matrix, const int n, const int m,
                                   const du::matrix<int>& indices) const {
        for(const auto& pair : indices) {
            int ri = pair[0];
            int ci = pair[1];
            
            for(int i = 0; i < n; i++) {
                matrix[i][ci]++;
            }
            
            for(int j = 0; j < m; j++) {
                matrix[ri][j]++;
            }
        }
    }
    
    int countOddCells(const du::matrix<int>& matrix, const int n, const int m) const {
        int count = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] % 2 == 1)
                    count++;
        return count;
    }
};


#endif
