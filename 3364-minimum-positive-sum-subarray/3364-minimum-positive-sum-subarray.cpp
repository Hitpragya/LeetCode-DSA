class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int arraySize = nums.size();
        vector<long long> prefixSum(arraySize + 1, 0);

        for (int index = 0; index < arraySize; index++) {
            prefixSum[index + 1] = prefixSum[index] + nums[index];
        }

        multiset<long long> validLeftPrefixSums;
        long long minimumPositiveSum = LLONG_MAX;

        for (int rightBoundary = l; rightBoundary <= arraySize; rightBoundary++) {
            validLeftPrefixSums.insert(prefixSum[rightBoundary - l]);

            int expiredLeftIndex = rightBoundary - r - 1;
            if (expiredLeftIndex >= 0) {
                validLeftPrefixSums.erase(
                    validLeftPrefixSums.find(prefixSum[expiredLeftIndex])
                );
            }

            auto upperBoundIterator = validLeftPrefixSums.upper_bound(prefixSum[rightBoundary] - 1);

            if (upperBoundIterator != validLeftPrefixSums.begin()) {
                --upperBoundIterator;
                minimumPositiveSum = min(
                    minimumPositiveSum,
                    prefixSum[rightBoundary] - *upperBoundIterator
                );
            }
        }

        return minimumPositiveSum == LLONG_MAX ? -1 : static_cast<int>(minimumPositiveSum);
    }
};