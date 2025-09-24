/**********************************************************************************************************************************************************************************************************************************************************************************
PROBLEM NUMBER 166:
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 4, denominator = 333
Output: "0.(012)"

***********************************************************************************************************************************************************************************************************************************************************************************/

CODE:
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        // Convert to long to avoid overflow
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);

        // Integer part
        result += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return result;

        result += ".";

        // Map to store remainder positions
        unordered_map<long long, int> remPos;
        while (rem != 0) {
            if (remPos.count(rem)) {
                result.insert(remPos[rem], "(");
                result += ")";
                break;
            }
            remPos[rem] = result.size();
            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
        }

        return result;
    }
};
