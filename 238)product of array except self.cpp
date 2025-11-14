/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
*/

#accepted code:==>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector <int> ans(n,1);
        vector<int> prefix(n,1);
        prefix[0]=1;
        //prefix
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }

        //suffix
        for(int i=n-2;i>=0;i--){
            ans[i]=ans[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            ans[i]*=prefix[i];
        }
        return ans;
    }
};


#MOST OPTIMIZED CODE FOR SPACE COMPLEXITY O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector <int> ans(n,1);
        
        ans[0]=1;
        //prefix
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        
        int suffix=1;
        //suffix
        for(int i=n-2;i>=0;i--){
            suffix=suffix*nums[i+1];
            ans[i]=ans[i]*suffix;
        }

       
        return ans;
    }
};
