/* PROBLEM STATEMENT
You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.

Return the minimum possible sum of the area of these rectangles.

Note that the rectangles are allowed to touch.

 

Example 1:

Input: grid = [[1,0,1],[1,1,1]]

Output: 5

Explanation:



The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
The 1 at (1, 1) is covered by a rectangle of area 1.
Example 2:

Input: grid = [[1,0,1,0],[0,1,0,1]]

Output: 5

Explanation:



The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
The 1 at (1, 1) is covered by a rectangle of area 1.
The 1 at (1, 3) is covered by a rectangle of area 1.
 

Constraints:

1 <= grid.length, grid[i].length <= 30
grid[i][j] is either 0 or 1.
The input is generated such that there are at least three 1's in grid.

*/




CODE 
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> ones;

        // Step 1: Collect all 1's positions
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    ones.emplace_back(i, j);

        int total = ones.size();
        int res = INT_MAX;

        // Step 2: Try all combinations of splitting into 3 groups
        for (int mask1 = 1; mask1 < (1 << total); ++mask1) {
            for (int mask2 = 1; mask2 < (1 << total); ++mask2) {
                if (mask1 & mask2) continue; // masks must be disjoint
                int mask3 = ((1 << total) - 1) ^ (mask1 | mask2);
                if (mask3 == 0) continue;

                vector<pair<int, int>> group1, group2, group3;
                for (int i = 0; i < total; ++i) {
                    if (mask1 & (1 << i)) group1.push_back(ones[i]);
                    else if (mask2 & (1 << i)) group2.push_back(ones[i]);
                    else group3.push_back(ones[i]);
                }

                auto area = [](const vector<pair<int, int>>& pts) {
                    int minX = INT_MAX, maxX = INT_MIN;
                    int minY = INT_MAX, maxY = INT_MIN;
                    for (auto& p : pts) {
                        minX = min(minX, p.first);
                        maxX = max(maxX, p.first);
                        minY = min(minY, p.second);
                        maxY = max(maxY, p.second);
                    }
                    return (maxX - minX + 1) * (maxY - minY + 1);
                };

                int a1 = area(group1);
                int a2 = area(group2);
                int a3 = area(group3);

                res = min(res, a1 + a2 + a3);
            }
        }

        return res;
    }
};
