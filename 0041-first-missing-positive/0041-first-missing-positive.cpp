class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();

        for (int index = 0; index < length; ++index) {
            while (nums[index] >= 1 && nums[index] <= length &&
                   nums[index] != index + 1 &&
                   nums[nums[index] - 1] != nums[index]) {
                swap(nums[index], nums[nums[index] - 1]);
            }
        }

        for (int index = 0; index < length; ++index) {
            if (nums[index] != index + 1) {
                return index + 1;
            }
        }

        return length + 1;
    }
};