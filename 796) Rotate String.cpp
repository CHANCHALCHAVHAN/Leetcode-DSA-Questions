/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=0;
        while(n< goal.length()){
            if(goal == s) return true;
            else{
                char temp = s[0];
                s[0]=s[1];
                s.erase(1 , 1);
                s.push_back(temp);
            }
            n++;

        }
        
        return false;
    }
};
