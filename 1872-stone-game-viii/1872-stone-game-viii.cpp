class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefixSum(n);
        prefixSum[0] = stones[0];

        for (int index = 1; index < n; ++index) {
            prefixSum[index] = prefixSum[index - 1] + stones[index];
        }

        long long bestDifference = prefixSum[n - 1];

        for (int index = n - 2; index >= 1; --index) {
            bestDifference = max(bestDifference, prefixSum[index] - bestDifference);
        }

        return static_cast<int>(bestDifference);
    }
};