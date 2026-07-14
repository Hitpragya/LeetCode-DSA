#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 200;

        vector<vector<int>> dp(maxVal + 1, vector<int>(maxVal + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> nextDp(maxVal + 1, vector<int>(maxVal + 1, 0));

            for (int g1 = 0; g1 <= maxVal; ++g1) {
                for (int g2 = 0; g2 <= maxVal; ++g2) {
                    int ways = dp[g1][g2];
                    if (ways == 0) continue;

                    nextDp[g1][g2] = (nextDp[g1][g2] + ways) % MOD;

                    int newG1 = (g1 == 0 ? x : std::gcd(g1, x));
                    nextDp[newG1][g2] = (nextDp[newG1][g2] + ways) % MOD;

                    int newG2 = (g2 == 0 ? x : std::gcd(g2, x));
                    nextDp[g1][newG2] = (nextDp[g1][newG2] + ways) % MOD;
                }
            }

            dp.swap(nextDp);
        }

        long long answer = 0;
        for (int g = 1; g <= maxVal; ++g) {
            answer = (answer + dp[g][g]) % MOD;
        }

        return (int)answer;
    }
};