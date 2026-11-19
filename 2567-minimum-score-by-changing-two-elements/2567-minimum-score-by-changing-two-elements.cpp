class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int changeTwoSmallest = nums[nums.size() - 1] - nums[2];
        int changeTwoLargest = nums[nums.size() - 3] - nums[0];
        int changeOneOfEach = nums[nums.size() - 2] - nums[1];

        return min({changeTwoSmallest, changeTwoLargest, changeOneOfEach});
    }
};