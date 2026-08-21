class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        vector<int> denominations;
        for (int coin : coins) {
            bool redundant = false;
            for (int smallerCoin : denominations) {
                if (coin % smallerCoin == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) {
                denominations.push_back(coin);
            }
        }

        int count = denominations.size();

        auto countValidAmounts = [&](long long limit) {
            long long total = 0;

            for (int mask = 1; mask < (1 << count); ++mask) {
                long long lcmValue = 1;
                bool exceedsLimit = false;

                for (int index = 0; index < count; ++index) {
                    if (mask & (1 << index)) {
                        long long commonDivisor = gcd(lcmValue, static_cast<long long>(denominations[index]));
                        lcmValue = lcmValue / commonDivisor * denominations[index];

                        if (lcmValue > limit) {
                            exceedsLimit = true;
                            break;
                        }
                    }
                }

                if (exceedsLimit) {
                    continue;
                }

                long long contribution = limit / lcmValue;

                if (__builtin_popcount(mask) % 2 == 1) {
                    total += contribution;
                } else {
                    total -= contribution;
                }
            }

            return total;
        };

        long long low = 1;
        long long high = 1LL * denominations[0] * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countValidAmounts(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};