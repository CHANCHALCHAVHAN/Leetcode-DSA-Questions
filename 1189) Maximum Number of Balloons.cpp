/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.

*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
       vector<int> freq(26 , 0);

       for(char ch : text){
    freq[ch - 'a'] += 1;
       }

       int char_b =  freq['b' - 'a'] ;
       int char_a = freq['a' - 'a'];
       int char_l = freq['l' - 'a'] / 2;
       int char_o = freq['o' - 'a'] /2;
       int char_n = freq['n' - 'a'];
       
       return min({char_a , char_b , char_l , char_o , char_n});
    }
};
