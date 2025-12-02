/*
You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]

Output: 3

Explanation:



There are three distinct ways to pick four points that form a horizontal trapezoid:

Using points [1,0], [2,0], [3,2], and [2,2].
Using points [2,0], [3,0], [3,2], and [2,2].
Using points [1,0], [3,0], [3,2], and [2,2].
Example 2:

Input: points = [[0,0],[1,0],[0,1],[2,1]]

Output: 1

Explanation:



There is only one horizontal trapezoid that can be formed.

 

Constraints:

4 <= points.length <= 105
–108 <= xi, yi <= 108
All points are pairwise distinct.
*/

class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long comb2(long long n) {
        if (n < 2) return 0;
        return (n * (n - 1) / 2) % MOD;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> freq;

        
        for (auto &p : points) {
            freq[p[1]]++;
        }

        vector<long long> pairs;
        long long sumP = 0;

        
        for (auto &it : freq) {
            long long c2 = comb2(it.second);
            pairs.push_back(c2);
            sumP = (sumP + c2) % MOD;
        }

    
        long long sumSq = 0;
        for (auto p : pairs) {
            sumSq = (sumSq + (p * p) % MOD) % MOD;
        }

        
        long long ans = ( (sumP * sumP) % MOD - sumSq + MOD ) % MOD;

        
        long long inv2 = 500000004LL; 
        ans = (ans * inv2) % MOD;

        return (int)ans;
    }
};
