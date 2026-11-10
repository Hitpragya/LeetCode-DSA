class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> minCost(n + 1, LLONG_MAX);
        minCost[0] = 0;

        for (int step = 1; step <= n; ++step) {
            for (int jump = 1; jump <= 3; ++jump) {
                int previousStep = step - jump;
                if (previousStep < 0) {
                    continue;
                }

                long long candidate = minCost[previousStep] + costs[step - 1] + 1LL * jump * jump;
                minCost[step] = min(minCost[step], candidate);
            }
        }

        return minCost[n];
    }
};