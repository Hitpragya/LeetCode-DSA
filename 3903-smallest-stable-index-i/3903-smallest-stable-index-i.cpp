class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMinimum(n);

        suffixMinimum[n - 1] = nums[n - 1];

        for (int index = n - 2; index >= 0; --index) {
            suffixMinimum[index] = min(nums[index], suffixMinimum[index + 1]);
        }

        int prefixMaximum = nums[0];

        for (int index = 0; index < n; ++index) {
            prefixMaximum = max(prefixMaximum, nums[index]);

            if (prefixMaximum - suffixMinimum[index] <= k) {
                return index;
            }
        }

        return -1;
    }
};
