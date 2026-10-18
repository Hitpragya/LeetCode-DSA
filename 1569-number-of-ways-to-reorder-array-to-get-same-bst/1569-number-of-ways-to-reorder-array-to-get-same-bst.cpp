class Solution {
    static constexpr int MOD = 1'000'000'007;
    vector<vector<int>> combinations;

    int countWays(vector<int>& values) {
        int total = values.size();
        if (total <= 1) return 1;

        vector<int> leftValues, rightValues;
        int root = values[0];

        for (int index = 1; index < total; ++index) {
            if (values[index] < root) {
                leftValues.push_back(values[index]);
            } else {
                rightValues.push_back(values[index]);
            }
        }

        long long leftWays = countWays(leftValues);
        long long rightWays = countWays(rightValues);
        long long interleaveWays = combinations[total - 1][leftValues.size()];

        return (leftWays * rightWays % MOD) * interleaveWays % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        combinations.assign(n + 1, vector<int>(n + 1, 1));

        for (int row = 2; row <= n; ++row) {
            for (int column = 1; column < row; ++column) {
                combinations[row][column] =
                    (combinations[row - 1][column - 1] +
                     combinations[row - 1][column]) % MOD;
            }
        }

        return (countWays(nums) - 1 + MOD) % MOD;
    }
};