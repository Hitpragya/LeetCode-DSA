class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0];
        int globalMax = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            currentMax = max(currentMax + nums[i], nums[i]);
            globalMax = max(globalMax, currentMax);
        }

        return globalMax;
    }
};