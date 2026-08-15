class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;

        for (int value : nums) {
            totalXor ^= value;
            hasNonZero = hasNonZero || (value != 0);
        }

        if (totalXor != 0) {
            return nums.size();
        }

        return hasNonZero ? nums.size() - 1 : 0;
    }
};