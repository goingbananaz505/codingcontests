#ifndef solution_h
#define solution_h

#include <vector>
#include "../Utils/datautils.h"

namespace du = datautils;

class Solution {
public:
    du::matrix<int> reconstructMatrix(const int upper, const int lower,
                                      const std::vector<int>& colsum) const {
        int matrixLength = static_cast<int>(colsum.size());
        du::matrix<int> matrix(2, std::vector<int>(matrixLength, 0));
        
        int onesToBeFilledInFirst = upper;
        int onesToBeFilledInSecond = lower;
        fillMatrixForColSumTwo(matrix, colsum, onesToBeFilledInFirst, onesToBeFilledInSecond);
        fillMatrixWithOnes(matrix, colsum, onesToBeFilledInFirst, onesToBeFilledInSecond);
        
        if(onesToBeFilledInFirst != 0 || onesToBeFilledInSecond != 0 || !sumDoesMatch(matrix, colsum)) {
            du::matrix<int> empty;
            return empty;
        }
        
        return matrix;
    }

private:
    void fillMatrixForColSumTwo(du::matrix<int>& matrix, const std::vector<int>& colsum, int& onesToBeFilledInFirst, int& onesToBeFilledInSecond) const {
        for(int i = 0; i < colsum.size(); i++) {
            if(colsum[i] == 2) {
                if(onesToBeFilledInFirst > 0) {
                    matrix[0][i] = 1;
                    onesToBeFilledInFirst--;
                }
                if(onesToBeFilledInSecond > 0) {
                    matrix[1][i] = 1;
                    onesToBeFilledInSecond--;
                }
            }
        }
    }
    
    void fillMatrixWithOnes(du::matrix<int>& matrix, const std::vector<int>& colsum,
                            int& onesToBeFilledInFirst, int& onesToBeFilledInSecond) const {
        for(int i = 0; i < colsum.size(); i++) {
            if(colsum[i] == 1) {
                if(onesToBeFilledInFirst != 0) {
                    matrix[0][i] = 1;
                    onesToBeFilledInFirst--;
                } else if(onesToBeFilledInSecond != 0) {
                    matrix[1][i] = 1;
                    onesToBeFilledInSecond--;
                }
            }
        }
    }
    
    bool sumDoesMatch(const du::matrix<int>& matrix, const std::vector<int>& colsum) const {
        for(int i = 0; i < colsum.size(); i++) {
            if(matrix[0][i] + matrix[1][i] != colsum[i]) {
                return false;
            }
        }
        
        return true;
    }
};

#endif
