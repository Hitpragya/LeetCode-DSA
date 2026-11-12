class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int arraySize = nums.size();
        int longestLength = 1;
        int increasingLength = 1;
        int decreasingLength = 1;

        for (int currentIndex = 1; currentIndex < arraySize; currentIndex++) {
            if (nums[currentIndex] > nums[currentIndex - 1]) {
                increasingLength++;
                decreasingLength = 1;
            } else if (nums[currentIndex] < nums[currentIndex - 1]) {
                decreasingLength++;
                increasingLength = 1;
            } else {
                increasingLength = 1;
                decreasingLength = 1;
            }

            longestLength = max(longestLength, max(increasingLength, decreasingLength));
        }

        return longestLength;
    }
};