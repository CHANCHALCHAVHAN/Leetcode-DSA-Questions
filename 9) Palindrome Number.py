'''
#Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
'''

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int partitions=0 , leftsum =0 , rightsum=0;
        for(int i=0;i<nums.size()-1;i++){
            leftsum+=nums[i];
            rightsum=0;//for new array from i+1 
            for(int j=i+1;j<nums.size();j++){
                rightsum+=nums[j];
            }
            if((leftsum+rightsum)%2==0){//true then we will decides its a positive sum difference
                partitions+=1;
            }
        }

        return partitions;
    }
};
