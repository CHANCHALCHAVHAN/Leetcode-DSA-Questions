/*
You are given a string s and an integer k.

First, you are allowed to change at most one index in s to another lowercase English letter.

After that, do the following partitioning operation until s is empty:

Choose the longest prefix of s containing at most k distinct characters.
Delete the prefix from s and increase the number of partitions by one. The remaining characters (if any) in s maintain their initial order.
Return an integer denoting the maximum number of resulting partitions after the operations by optimally choosing at most one index to change.

 

Example 1:

Input: s = "accca", k = 2

Output: 3

Explanation:

The optimal way is to change s[2] to something other than a and c, for example, b. then it becomes "acbca".

Then we perform the operations:

The longest prefix containing at most 2 distinct characters is "ac", we remove it and s becomes "bca".
Now The longest prefix containing at most 2 distinct characters is "bc", so we remove it and s becomes "a".
Finally, we remove "a" and s becomes empty, so the procedure ends.
Doing the operations, the string is divided into 3 partitions, so the answer is 3.

Example 2:

Input: s = "aabaab", k = 3

Output: 1

Explanation:

Initially s contains 2 distinct characters, so whichever character we change, it will contain at most 3 distinct characters, so the longest prefix with at most 3 distinct characters would always be all of it, therefore the answer is 1.

Example 3:

Input: s = "xxyz", k = 1

Output: 4

Explanation:

The optimal way is to change s[0] or s[1] to something other than characters in s, for example, to change s[0] to w.

Then s becomes "wxyz", which consists of 4 distinct characters, so as k is 1, it will divide into 4 partitions.

 

Constraints:

1 <= s.length <= 104
s consists only of lowercase English letters.
1 <= k <= 26
*/

#CODE::=>
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<int> pref(n), suff(n), partition_start(n);
        
        // Helper function to compute partitions from left to right
        auto computePartitions = [&](const string& str, vector<int>& partitions, vector<int>& start) {
            unordered_map<char, int> freq;
            int count = 0, l = 0;
            for (int r = 0; r < n; ++r) {
                freq[str[r]]++;
                while (freq.size() > k) {
                    freq[str[l]]--;
                    if (freq[str[l]] == 0) freq.erase(str[l]);
                    l++;
                }
                if (r == n - 1 || freq.size() > k || (r + 1 < n && freq.find(str[r + 1]) == freq.end() && freq.size() == k)) {
                    count++;
                    for (int i = l; i <= r; ++i) {
                        partitions[i] = count;
                        start[i] = l;
                    }
                    l = r + 1;
                    freq.clear();
                }
            }
        };

        // Compute prefix partitions
        computePartitions(s, pref, partition_start);

        // Compute suffix partitions
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        vector<int> reversed_suff(n), reversed_start(n);
        computePartitions(reversed_s, reversed_suff, reversed_start);
        reverse(reversed_suff.begin(), reversed_suff.end());

        // Try all possible replacements
        int max_parts = pref[n - 1]; // No change case
        for (int i = 0; i < n; ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == s[i]) continue;
                string temp = s;
                temp[i] = c;

                // Recompute partitions for modified string
                vector<int> temp_pref(n), temp_start(n);
                computePartitions(temp, temp_pref, temp_start);
                vector<int> temp_suff(n), temp_suff_start(n);
                string temp_rev = temp;
                reverse(temp_rev.begin(), temp_rev.end());
                computePartitions(temp_rev, temp_suff, temp_suff_start);
                reverse(temp_suff.begin(), temp_suff.end());

                max_parts = max(max_parts, temp_pref[n - 1]);
            }
        }

        return max_parts;
    }
};
