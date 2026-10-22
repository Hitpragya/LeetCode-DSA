class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool increasingRight = true;
        bool increasingLeft = true;

        for (int value = 0; value < n; ++value) {
            int rightIndex = (zero + value) % n;
            int leftIndex = ((zero - value) % n + n) % n;

            if (nums[rightIndex] != value) {
                increasingRight = false;
            }

            if (nums[leftIndex] != value) {
                increasingLeft = false;
            }
        }

        int minimumOperations = INT_MAX;

        if (increasingRight) {
            minimumOperations = min(minimumOperations, zero);
            minimumOperations = min(minimumOperations, (n - zero) % n + 2);
        }

        if (increasingLeft) {
            minimumOperations = min(minimumOperations, (zero + 1) % n + 1);
            minimumOperations = min(minimumOperations, 1 + (n - zero - 1) % n);
        }

        return minimumOperations == INT_MAX ? -1 : minimumOperations;
    }
};