/*
No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

 

Example 1:

Input: n = 2
Output: [1,1]
Explanation: Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.
Example 2:

Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.
 

Constraints:

2 <= n <= 104
*/
class Solution {
public:
    bool containsZero(int num) {
    if (num == 0) return true;  // edge case

    num = abs(num);             // handle negative numbers
    while (num > 0) {
        if (num % 10 == 0)
            return true;
        num /= 10;
    }
    return false;
}

    vector<int> getNoZeroIntegers(int n) {
     vector<int> v;
     int i=1;
     int j=1;
     for( i=1 ; i<n ; i++){
        for( j=i ; j<n ; j++){
        bool ihaszero = containsZero(i);
        bool jhasZero = containsZero(j);
        if((ihaszero == false )&& (jhasZero ==false)){
            if((i+j)==n){
                v.push_back(i);
                v.push_back(j);
                return v;
            }
        }
     }  
    }
    return v;
    }
};
