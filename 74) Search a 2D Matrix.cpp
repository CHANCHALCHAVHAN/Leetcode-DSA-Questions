/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size() , n = matrix[0].size() ;
      int stR = 0 , endR = m-1;
      int corrR = -1 ;
      while(stR <= endR){
        int midR = stR + (endR-stR)/2 ;
        if((matrix[midR][0] <= target) && (matrix[midR][n-1] >= target)){
            corrR = midR;
            break;
        }
        else if(matrix[midR][0] >= target){
            endR = midR-1;
        }
        else{
            stR = midR+1 ;
        }

      }

      stR = 0 , endR = n-1;
      while(stR <= endR && corrR != -1){
        int mid = stR + (endR - stR)/2 ;
        if(target == matrix[corrR][mid]){
            return true ;
        }
        else if( matrix[corrR][mid] >= target ){
            endR = mid-1;
        }
        else{
            stR = mid+1 ;
        }
      }


        return false;
    }
};
