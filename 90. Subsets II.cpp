/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution {
public:
   void AllSubsets(vector<int>& nums , set<vector<int>> & ans , vector<int> &subsets , int i  ){
        if(i == nums.size()) {
            if(ans.find(subsets) == ans.end())
                { 
                  ans.insert({subsets});
                }
                return ;
        }

        subsets.push_back(nums[i]);//inclusion
        AllSubsets(nums , ans , subsets , i+1);
        subsets.pop_back();//backatracking
        AllSubsets(nums , ans , subsets , i+1);//execlusion


    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set <vector<int>> ans ;
        vector<vector<int>> answer;
        vector<int>subsets ;
        sort(nums.begin() , nums.end());
        int i =0 ;
        AllSubsets(nums , ans , subsets , i);
        for(auto val : ans)
            answer.push_back(val);

        return answer ;
    }
};
