/*
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

 

Example 1:


Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
Example 2:


Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
 

Constraints:

1 <= n <= 231 - 1
*/
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
      int row=0;
      int coin =n;
      if(n==1){
            return 1;
        }
      for(int i=1 ; i<=coin ; i++){       
        n= n-i;
        
        if(n<0){
            return row;
        }
        row+=1;
        
      } 
      return 0; 
    }
};
