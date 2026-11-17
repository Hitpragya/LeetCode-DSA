class Solution {
public:
    int minimumChanges(string s, int k) {
        int length = s.size();
        const int INF = INT_MAX / 2;

        vector<vector<int>> divisors(length + 1);
        for (int size = 2; size <= length; ++size) {
            for (int divisor = 1; divisor < size; ++divisor) {
                if (size % divisor == 0) {
                    divisors[size].push_back(divisor);
                }
            }
        }

        vector<vector<int>> cost(length, vector<int>(length, INF));
        for (int left = 0; left < length; ++left) {
            for (int right = left + 1; right < length; ++right) {
                int size = right - left + 1;

                for (int divisor : divisors[size]) {
                    int changes = 0;

                    for (int residue = 0; residue < divisor; ++residue) {
                        int low = left + residue;
                        int high = right - (divisor - 1 - residue);

                        while (low < high) {
                            if (s[low] != s[high]) {
                                ++changes;
                            }
                            low += divisor;
                            high -= divisor;
                        }
                    }

                    cost[left][right] = min(cost[left][right], changes);
                }
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(length + 1, INF));
        dp[0][0] = 0;

        for (int pieces = 1; pieces <= k; ++pieces) {
            for (int end = 2 * pieces; end <= length; ++end) {
                for (int start = 2 * (pieces - 1); start + 1 < end; ++start) {
                    if (dp[pieces - 1][start] == INF) {
                        continue;
                    }

                    dp[pieces][end] = min(
                        dp[pieces][end],
                        dp[pieces - 1][start] + cost[start][end - 1]
                    );
                }
            }
        }

        return dp[k][length];
    }
};