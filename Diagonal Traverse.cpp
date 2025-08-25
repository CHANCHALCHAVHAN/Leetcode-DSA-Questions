/*
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105

*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);

        int row = 0, col = 0;
        bool up = true;  // direction flag

        while (result.size() < m * n) {
            result.push_back(mat[row][col]);

            if (up) {  
                // moving upwards (↗)
                if (col == n - 1) { // hit right boundary
                    row++;
                    up = false;
                } else if (row == 0) { // hit top boundary
                    col++;
                    up = false;
                } else { // normal move
                    row--;
                    col++;
                }
            } else {  
                // moving downwards (↙)
                if (row == m - 1) { // hit bottom boundary
                    col++;
                    up = true;
                } else if (col == 0) { // hit left boundary
                    row++;
                    up = true;
                } else { // normal move
                    row++;
                    col--;
                }
            }
        }
        return result;
    }
};


