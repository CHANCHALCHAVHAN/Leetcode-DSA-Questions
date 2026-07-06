/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
       int m = mat.size() , n  = mat[0].size();
       int srow = 0 , scol = 0 ;
       int erow = m-1 , ecol = n-1 ;
       vector<int> ans;

       while(srow<=erow && scol<=ecol){
        //top
        for(int j = scol ; j < ecol ; j++){
            ans.push_back(mat[srow][j]);
        }

        //right
        for(int i = srow ; i <= erow ; i++ ){
            ans.push_back(mat[i][ecol]);
        }

        //bottom
        for(int j = ecol-1 ; j >= scol ; j--){
            if(srow == erow) {
                break;
            }
            ans.push_back(mat[erow][j]);
        }

        //left
        for(int i = erow-1 ; i >= srow+1; i-- ){
            if(ecol == scol) {
                break;
            }
            ans.push_back(mat[i][scol]);
        }
        srow++ ; 
        scol ++ ;
        erow-- ; 
        ecol--; 
       }

       return ans;
    }
};
