#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(n, std::vector<int>(m, 0));
        incrementIndiciesInMatrix(matrix, n, m, indices);
        return countOddCells(matrix, n, m);
    }
private:
    void incrementIndiciesInMatrix(vector<vector<int>>& matrix, int n, int m, const vector<vector<int>>& indices) {
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
    
    int countOddCells(const vector<vector<int>>& matrix, int n, int m) {
        int count = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] % 2 == 1)
                    count++;
        return count;
    }
};


int main(int argc, const char * argv[]) {
    int n = 2;
    int m = 3;
    vector<vector<int>> indices = { { 0,1 }, { 1,1 } };
    
    Solution s;
    cout << s.oddCells(n, m, indices) << endl;
    
    return 0;
}
