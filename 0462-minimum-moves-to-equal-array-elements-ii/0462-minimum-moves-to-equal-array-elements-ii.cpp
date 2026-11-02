class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int medianIndex = n / 2;

        nth_element(nums.begin(), nums.begin() + medianIndex, nums.end());
        int median = nums[medianIndex];

        long long totalMoves = 0;
        for (int value : nums) {
            totalMoves += abs(value - median);
        }

        return totalMoves;
    }
};