class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> presentValues(nums.begin(), nums.end());

        int sequentialSum = nums[0];

        for (int index = 1; index < nums.size(); ++index) {
            if (nums[index] != nums[index - 1] + 1) {
                break;
            }
            sequentialSum += nums[index];
        }

        int candidate = sequentialSum;

        while (presentValues.count(candidate)) {
            ++candidate;
        }

        return candidate;
    }
};