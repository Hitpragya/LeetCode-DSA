class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long oddSubarrayCount = 0;
        long long evenPrefixCount = 1;
        long long oddPrefixCount = 0;
        int currentParity = 0;

        for (int value : arr) {
            currentParity ^= (value & 1);

            if (currentParity == 1) {
                oddSubarrayCount = (oddSubarrayCount + evenPrefixCount) % MOD;
                oddPrefixCount++;
            } else {
                oddSubarrayCount = (oddSubarrayCount + oddPrefixCount) % MOD;
                evenPrefixCount++;
            }
        }

        return static_cast<int>(oddSubarrayCount);
    }
};