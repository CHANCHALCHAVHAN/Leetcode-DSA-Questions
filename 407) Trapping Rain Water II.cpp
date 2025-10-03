/*************************************************************************************************************************************************************************************************************************************************************************************
Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

Example 1:


Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.
Example 2:


Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
 

Constraints:

m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 104

*************************************************************************************************************************************************************************************************************************************************************************************/

#CODE 
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0;

        // Min-heap to store boundary cells: {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all boundary cells into the heap
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = visited[m - 1][j] = true;
        }

        int trappedWater = 0;
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int maxHeight = 0;

        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            int h = cell[0], x = cell[1], y = cell[2];
            maxHeight = max(maxHeight, h);

            for (auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    int nh = heightMap[nx][ny];
                    if (nh < maxHeight) {
                        trappedWater += maxHeight - nh;
                    }
                    pq.push({nh, nx, ny});
                }
            }
        }

        return trappedWater;
    }
};
