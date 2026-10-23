class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int maximumK = -1;
        int size = nums.size();

        for (int index = 0; index < size; index++) {
            if (nums[index] != index) {
                if (maximumK == -1) {
                    maximumK = nums[index];
                } else {
                    maximumK &= nums[index];
                }
            }
        }

        return max(maximumK, 0);
    }
};