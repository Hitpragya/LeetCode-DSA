#include <vector>
#include <algorithm>

class Solution {
public:
    int gcdOfMinAndMax(int a, int b) {
        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    int findGCD(std::vector<int>& nums) {
        int minimumValue = nums[1];
        int maximumValue = nums[1];

        for (int value : nums) {
            if (value < minimumValue) {
                minimumValue = value;
            }
            if (value > maximumValue) {
                maximumValue = value;
            }
        }

        return gcdOfMinAndMax(minimumValue, maximumValue);
    }
};