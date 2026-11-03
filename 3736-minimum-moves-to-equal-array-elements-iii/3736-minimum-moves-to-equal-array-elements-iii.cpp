class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());
        int totalMoves = 0;

        for (int value : nums) {
            totalMoves += maxValue - value;
        }

        return totalMoves;
    }
};