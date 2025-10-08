/*************************************************
You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

 

Example 1:

Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.
Example 2:

Input: spells = [3,1,2], potions = [8,5,8], success = 16
Output: [2,0,2]
Explanation:
- 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
- 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. 
- 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful. 
Thus, [2,0,2] is returned.
 

Constraints:

n == spells.length
m == potions.length
1 <= n, m <= 105
1 <= spells[i], potions[i] <= 105
1 <= success <= 1010
 
Discover more
Get coding challenge books
Seen this question in a real interview before?
1/5
Yes
No
Accepted
310,466/647.9K
Acceptance Rate
47.9%
Topics
icon
Companies
Hint 1
Notice that if a spell and potion pair is successful, then the spell and all stronger potions will be successful too.
Hint 2
Thus, for each spell, we need to find the potion with the least strength that will form a successful pair.
Hint 3
We can efficiently do this by sorting the potions based on strength and using binary search.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> result;

        for (int spell : spells) {
            // Minimum potion strength needed for success
            long long minPotion = (success + spell - 1) / spell; // ceil(success / spell)
            // Find the first potion >= minPotion using lower_bound
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            result.push_back(m - (it - potions.begin()));
        }

        return result;
    }
};


