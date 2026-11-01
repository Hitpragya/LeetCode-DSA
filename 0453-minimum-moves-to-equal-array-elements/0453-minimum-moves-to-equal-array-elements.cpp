class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minimumValue = *min_element(nums.begin(), nums.end());
        long long totalMoves = 0;

        for (int value : nums) {
            totalMoves += value - minimumValue;
        }

        return static_cast<int>(totalMoves);
    }
};