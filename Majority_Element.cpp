/*
169. Majority Element
Solved
Easy
Topics
premium lock icon
Companies
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

  */

####CODE:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int cs=0;
        int maxsum=INT_MIN;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            cs+=nums[i];
            maxsum=max(cs,maxsum);
            if(cs<0){
                cs=0;
            }
        }
        return maxsum;
        
    }
};




