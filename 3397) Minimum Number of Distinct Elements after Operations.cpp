/*
You are given an integer array nums and an integer k.

You are allowed to perform the following operation on each element of the array at most once:

Add an integer in the range [-k, k] to the element.
Return the maximum possible number of distinct elements in nums after performing the operations.

 

Example 1:

Input: nums = [1,2,2,3,3,4], k = 2

Output: 6

Explanation:

nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first four elements.

Example 2:

Input: nums = [4,4,4,4], k = 1

Output: 3

Explanation:

By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4, 4].

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 109
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
51,552/115.9K
Acceptance Rate
44.5%
Topics
icon
Companies
Hint 1
Can we use sorting here?
Hint 2
Find the minimum element which is not used for each element.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        unordered_set<long long> used;
        sort(nums.begin(), nums.end());

        for (int num : nums) {
            // Try to assign the smallest unused value in [num - k, num + k]
            for (int delta = -k; delta <= k; ++delta) {
                long long candidate = (long long)num + delta;
                if (!used.count(candidate)) {
                    used.insert(candidate);
                    break;
                }
            }
        }

        return used.size();
    }
};
