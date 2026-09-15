class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        for (int left = n - 1; left >= 0; --left) {
            for (int right = left; right < n; ++right) {
                if (s[left] == s[right] &&
                    (right - left < 2 || isPalindrome[left + 1][right - 1])) {
                    isPalindrome[left][right] = true;
                }
            }
        }

        vector<int> dp(n + 1, 0);

        for (int length = 1; length <= n; ++length) {
            dp[length] = dp[length - 1];

            int start = length - k;
            if (start >= 0 && isPalindrome[start][length - 1]) {
                dp[length] = max(dp[length], dp[start] + 1);
            }

            start = length - k - 1;
            if (start >= 0 && isPalindrome[start][length - 1]) {
                dp[length] = max(dp[length], dp[start] + 1);
            }
        }

        return dp[n];
    }
};