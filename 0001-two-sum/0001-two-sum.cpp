class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueToIndex;

        for (int currentIndex = 0; currentIndex < nums.size(); currentIndex++) {
            int currentValue = nums[currentIndex];
            int requiredValue = target - currentValue;

            if (valueToIndex.find(requiredValue) != valueToIndex.end()) {
                return {valueToIndex[requiredValue], currentIndex};
            }

            valueToIndex[currentValue] = currentIndex;
        }

        return {};
    }
};