/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0
 

Constraints:

0 <= num <= 231 - 1
*/
class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n!=0){
            sum+= n%10;
            n=n/10;
        }
        return sum;
    }
    int addDigits(int num) {
    int sum = digitSum(num);
    while(true){
        if((sum/10)==0){
            return sum;
        }
        else{
            sum=digitSum(sum);
        }
    }
    return 0;
    }
};
