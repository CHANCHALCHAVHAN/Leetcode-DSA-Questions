/*************************************************************************************************************************************************************************************************************************************************************************************
Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake that is full of water, there will be a flood. Your goal is to avoid floods in any lake.

Given an integer array rains where:

rains[i] > 0 means there will be rains over the rains[i] lake.
rains[i] == 0 means there are no rains this day and you can choose one lake this day and dry it.
Return an array ans where:

ans.length == rains.length
ans[i] == -1 if rains[i] > 0.
ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.

Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes.

 

Example 1:

Input: rains = [1,2,3,4]
Output: [-1,-1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day full lakes are [1,2,3]
After the fourth day full lakes are [1,2,3,4]
There's no day to dry any lake and there is no flood in any lake.
Example 2:

Input: rains = [1,2,0,0,2,1]
Output: [-1,-1,2,1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day, we dry lake 2. Full lakes are [1]
After the fourth day, we dry lake 1. There is no full lakes.
After the fifth day, full lakes are [2].
After the sixth day, full lakes are [1,2].
It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another acceptable scenario.
Example 3:

Input: rains = [1,2,0,1,2]
Output: []
Explanation: After the second day, full lakes are  [1,2]. We have to dry one lake in the third day.
After that, it will rain over lakes [1,2]. It's easy to prove that no matter which lake you choose to dry in the 3rd day, the other one will flood.
 

Constraints:

1 <= rains.length <= 105
0 <= rains[i] <= 109
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
44,293/157.2K
Acceptance Rate
28.2%
Topics
icon
Companies
Hint 1
Keep An array of the last day there was rains over each city.
Hint 2
Keep an array of the days you can dry a lake when you face one.
Hint 3
When it rains over a lake, check the first possible day you can dry this lake and assign this day to this lake.

*************************************************************************************************************************************************************************************************************************************************************************************/

#CODE 
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> lakeLastFilled; // lake -> last filled day
        set<int> dryDays; // indices of days we can dry
        vector<int> ans(n, 1); // default dry lake is 1
        map<int, set<int>> lakeToRainDays; // lake -> all rain days

        // Preprocess: map each lake to its rain days
        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                lakeToRainDays[rains[i]].insert(i);
            }
        }

        set<pair<int, int>> nextRain; // {next rain day, lake}

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];
                ans[i] = -1;

                if (lakeLastFilled.count(lake)) {
                    // Lake is already full, need to dry it before today
                    auto it = dryDays.lower_bound(lakeLastFilled[lake] + 1);
                    if (it == dryDays.end()) return {}; // no dry day available
                    ans[*it] = lake;
                    dryDays.erase(it);
                }

                lakeLastFilled[lake] = i;

            } else {
                dryDays.insert(i);
            }
        }

        return ans;
    }
};
