class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;

        for (int value : nums) {
            totalSum += value;
        }

        int targetSum = totalSum - x;

        if (targetSum < 0) {
            return -1;
        }

        int left = 0;
        int currentSum = 0;
        int longestLength = -1;

        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];

            while (currentSum > targetSum) {
                currentSum -= nums[left];
                left++;
            }

            if (currentSum == targetSum) {
                longestLength = max(longestLength, right - left + 1);
            }
        }

        return longestLength == -1 ? -1 : nums.size() - longestLength;
    }
};