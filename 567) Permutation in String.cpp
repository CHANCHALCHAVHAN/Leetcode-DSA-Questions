/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/
#include <algorithm>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int frequency[26];
       for(int i=0 ; i<s1.length();i++){
        frequency[s1[i]-'a'] += 1;
       }
       int windowfrequency[26];
       int st=0;
       int end=s1.length()-1;

       while(end < s2.length()){
        std::fill(std::begin(windowfrequency), std::end(windowfrequency), 0);
        for(int i=st; i<= end; i++){
            windowfrequency[s2[i]-'a'] += 1;
        }
        if(std::equal(std::begin(frequency), std::end(frequency), std::begin(windowfrequency)) == true){
            return true;
        }
        else{
            
            st++;
            end++ ;
        }
       } 
       return false;
    }
};
