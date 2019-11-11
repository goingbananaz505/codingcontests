#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(const int upper, const int lower, vector<int>& colsum) {
        int matrixLength = colsum.size();
        vector<vector<int>> matrix(2, vector<int>(matrixLength, 0));
        
        int onesToBeFilledInFirst = upper;
        int onesToBeFilledInSecond = lower;
        fillMatrixForColSumTwo(matrix, colsum, onesToBeFilledInFirst, onesToBeFilledInSecond);
        fillMatrixWithOnes(matrix, colsum, onesToBeFilledInFirst, onesToBeFilledInSecond);
        
        if(onesToBeFilledInFirst != 0 || onesToBeFilledInSecond != 0 || !sumDoesMatch(matrix, colsum)) {
            vector<vector<int>> empty;
            return empty;
        }
        
        return matrix;
    }

private:
    void fillMatrixForColSumTwo(vector<vector<int>>& matrix, const vector<int>& colsum, int& onesToBeFilledInFirst, int& onesToBeFilledInSecond) {
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
    
    void fillMatrixWithOnes(vector<vector<int>>& matrix, const vector<int>& colsum, int& onesToBeFilledInFirst, int& onesToBeFilledInSecond) {
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
    
    bool sumDoesMatch(const vector<vector<int>>& matrix, const vector<int>& colsum) {
        for(int i = 0; i < colsum.size(); i++) {
            if(matrix[0][i] + matrix[1][i] != colsum[i]) {
                return false;
            }
        }
        
        return true;
    }
};


int main(int argc, const char * argv[]) {
    int upper = 2;
    int lower = 1;
    vector<int> colsum = { 1, 1, 1 };
    
    Solution s;
    auto matrix = s.reconstructMatrix(upper, lower, colsum);
    for(const auto& row : matrix) {
        for(const auto& element : row)
            cout << element << " ";
        cout << endl;
    }
    
    return 0;
}
