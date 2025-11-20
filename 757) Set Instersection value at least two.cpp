/*

You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

A containing set is an array nums where each interval from intervals has at least two integers in nums.

For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
Return the minimum possible size of a containing set.

 

Example 1:

Input: intervals = [[1,3],[3,7],[8,9]]
Output: 5
Explanation: let nums = [2, 3, 4, 8, 9].
It can be shown that there cannot be any containing array of size 4.
Example 2:

Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
Output: 3
Explanation: let nums = [2, 3, 4].
It can be shown that there cannot be any containing array of size 2.
Example 3:

Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
Output: 5
Explanation: let nums = [1, 2, 3, 4, 5].
It can be shown that there cannot be any containing array of size 4.
 

Constraints:

1 <= intervals.length <= 3000
intervals[i].length == 2
0 <= starti < endi <= 108
*/

#Strategy
- Sort intervals by their end points in ascending order. If two intervals have the same end, sort by start in descending order. This ensures we process tighter intervals first.
- Maintain a result set res and a list chosen of selected points.
- For each interval, count how many elements from chosen already lie within it.
- If fewer than 2, add the largest possible new elements from the interval to chosen to make up the difference.

#code:
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end ascending, start descending
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });

        vector<int> chosen;
        for (const auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            int count = 0;

            // Count how many chosen elements are in [start, end]
            for (int i = chosen.size() - 1; i >= 0 && chosen[i] >= start; --i) {
                if (chosen[i] <= end) count++;
            }

            // Add missing elements from the right end
            for (int i = end; count < 2 && i >= start; --i) {
                if (chosen.empty() || chosen.back() != i) {
                    chosen.push_back(i);
                    count++;
                }
            }
        }

        return chosen.size();
    }
};
