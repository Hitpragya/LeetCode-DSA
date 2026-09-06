class Solution {
public:
    int numDistinct(string s, string t) {
        int sourceLength = s.size();
        int targetLength = t.size();

        if (targetLength > sourceLength) {
            return 0;
        }

        vector<unsigned long long> dp(targetLength + 1, 0);
        dp[0] = 1;

        for (char sourceCharacter : s) {
            for (int targetIndex = targetLength; targetIndex >= 1; --targetIndex) {
                if (sourceCharacter == t[targetIndex - 1]) {
                    dp[targetIndex] += dp[targetIndex - 1];
                }
            }
        }

        return static_cast<int>(dp[targetLength]);
    }
};