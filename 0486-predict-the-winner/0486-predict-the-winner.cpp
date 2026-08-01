class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(nums.begin(), nums.end());

        for (int left = n - 2; left >= 0; --left) {
            for (int right = left + 1; right < n; ++right) {
                long long takeLeft = nums[left] - dp[right];
                long long takeRight = nums[right] - dp[right - 1];
                dp[right] = max(takeLeft, takeRight);
            }
        }

        return dp[n - 1] >= 0;
    }
};