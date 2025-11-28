/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n=nums.size();
        int st=0;
        int end=n-1;
        long long int mid=st+(end-st)/2;
        while(st<=end){
            mid=st+(end-st)/2;
            if(mid==0){
                return nums[mid];
            }
             else if (mid%2==0){
                if(nums[mid-1]!= nums[mid] && nums[mid]!=nums[mid+1])
                    return nums[mid];
                else if(nums[mid]==nums[mid-1])
                    end=mid-1;
                else
                    st=mid+1;
            }
            else{
                if(nums[mid-1]!= nums[mid] && nums[mid]!=nums[mid+1])
                    return nums[mid];
                else if(nums[mid]==nums[mid-1])
                    st=mid+1;
                else
                    end=mid-1;
            }
        }

      return 0;  
    }
};
