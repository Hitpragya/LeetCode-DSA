class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6.0;
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;

        double angleDifference = abs(hourAngle - minuteAngle);
        return min(angleDifference, 360.0 - angleDifference);
    }
};