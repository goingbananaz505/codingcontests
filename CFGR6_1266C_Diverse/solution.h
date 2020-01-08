#ifndef solution_h
#define solution_h

#include "../Utils/datautils.h"

namespace du = datautils;

class Solution {
public:
    bool isDiverseMatrixPossible(const int rows, const int columns, du::matrix<int>& matrix) {
        if(rows == 1 && columns == 1) {
            return false;
        }
        
        matrix.resize(rows);
        for(auto& row : matrix) {
            row.resize(columns);
        }
        
        if(rows == 1 || columns == 1) {
            int start = 2;
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    matrix[i][j] = start;
                    start++;
                }
            }
        }
        else {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    matrix[i][j] = (j + 1) * (columns + i + 1);
                }
            }
        }
        
        return true;
    }
private:
    
};

#endif
