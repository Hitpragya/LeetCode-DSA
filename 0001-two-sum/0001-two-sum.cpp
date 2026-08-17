class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexByValue;

        for (int currentIndex = 0; currentIndex < nums.size(); ++currentIndex) {
            int complement = target - nums[currentIndex];

            if (indexByValue.count(complement)) {
                return {indexByValue[complement], currentIndex};
            }

            indexByValue[nums[currentIndex]] = currentIndex;
        }

        return {};
    }
};