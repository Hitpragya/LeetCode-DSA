class Solution {
    vector<int> prefix;
    vector<vector<int>> memo;

    int solve(int left, int right) {
        if (left >= right) {
            return 0;
        }

        int& answer = memo[left][right];

        if (answer != -1) {
            return answer;
        }

        answer = 0;

        for (int mid = left; mid < right; ++mid) {
            int leftSum = prefix[mid + 1] - prefix[left];
            int rightSum = prefix[right + 1] - prefix[mid + 1];

            if (leftSum < rightSum) {
                answer = max(answer, leftSum + solve(left, mid));
            } else if (leftSum > rightSum) {
                answer = max(answer, rightSum + solve(mid + 1, right));
            } else {
                answer = max(answer, leftSum + max(solve(left, mid), solve(mid + 1, right)));
            }
        }

        return answer;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        memo.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};