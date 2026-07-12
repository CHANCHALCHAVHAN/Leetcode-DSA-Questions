/*

Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.


*/

class Solution {
public:

    bool isPalindrome(string s , int st , int end){
        while(st < end){
            if(s[st] != s[end]){
                return false;
            }
            st++ ;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        if(s.length() > 0) ans= s[0] ;
        int st = 0 , end = s.length()-1 ;

        while(st < end ){
            bool status = isPalindrome(s , st , end);
            if(status == true){
                if(ans.length() < end- st +1){
                    ans = s.substr(st ,end - st + 1);
                }
            }
            if(s[st+1] == s[end]) {
                st++;}

            else if(s[st] == s[end-1]) {
                end--;}

            else {
                end-- ; 
                st++;
            }
        }
        return ans;
    }
};
