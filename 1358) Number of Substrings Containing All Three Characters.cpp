/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<int> freq(3, 0);   // track counts of 'a','b','c'
        int left = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;

            // shrink window until it still contains all 3 chars
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // every substring starting at left and ending at >= right is valid
                count += n - right;
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return count;
    }
};
