class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int index = 0; index < n; ++index) {
            int value = nums[index];
            int digitSum = 0;
            while (value > 0) {
                digitSum += value % 10;
                value /= 10;
            }
            if (digitSum == index) {
                return index;
            }
        }
        return -1;
    }
};