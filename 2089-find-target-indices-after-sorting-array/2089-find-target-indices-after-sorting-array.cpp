class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smallerCount = 0;
        int targetCount = 0;

        for (int value : nums) {
            if (value < target) {
                smallerCount++;
            } else if (value == target) {
                targetCount++;
            }
        }

        vector<int> targetIndices;
        targetIndices.reserve(targetCount);

        for (int index = smallerCount; index < smallerCount + targetCount; index++) {
            targetIndices.push_back(index);
        }

        return targetIndices;
    }
};