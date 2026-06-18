/*
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.

 

Example 1:


Input: hour = 12, minutes = 30
Output: 165
Example 2:


Input: hour = 3, minutes = 30
Output: 75
Example 3:


Input: hour = 3, minutes = 15
Output: 7.5
 

Constraints:

1 <= hour <= 12
0 <= minutes <= 59
 
Discover more
Clock
Clocks


*/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans ;
        if(hour == 12){
            hour = 0;
        }
        ans = std::abs((30* hour) - (5.5* minutes));

        return min(ans , 360-ans);
    }
};
