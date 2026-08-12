class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        int left = 0;
        int maximumLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            ++frequency[nums[right]];

            while (frequency[nums[right]] > k) {
                --frequency[nums[left]];
                ++left;
            }

            maximumLength = max(maximumLength, right - left + 1);
        }

        return maximumLength;
    }
};