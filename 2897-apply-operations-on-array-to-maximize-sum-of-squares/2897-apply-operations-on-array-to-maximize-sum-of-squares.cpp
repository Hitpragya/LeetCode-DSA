class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        vector<long long> selected(k, 0);
        vector<int> bitCount(30, 0);

        for (int value : nums) {
            for (int bit = 0; bit < 30; bit++) {
                if (value & (1 << bit)) {
                    bitCount[bit]++;
                }
            }
        }

        for (int bit = 29; bit >= 0; bit--) {
            long long power = 1LL << bit;
            int available = min(bitCount[bit], k);

            for (int index = 0; index < available; index++) {
                selected[index] += power;
            }
        }

        long long answer = 0;
        for (int index = 0; index < k; index++) {
            answer = (answer + selected[index] * selected[index]) % MOD;
        }

        return static_cast<int>(answer);
    }
};