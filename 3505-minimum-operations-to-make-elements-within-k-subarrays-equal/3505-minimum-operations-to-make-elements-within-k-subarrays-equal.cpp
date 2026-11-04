class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost = getMinOps(nums, x);

        const long long INF = LLONG_MAX / 2;

        // memo[i][remaining] = answer for nums[i..n-1]
        vector<vector<long long>> memo(
            n + 1, vector<long long>(k + 1, -1));

        return solve(nums, x, 0, k, cost, memo, INF);
    }

private:
    long long solve(const vector<int>& nums,
                    int x,
                    int i,
                    int remaining,
                    const vector<long long>& cost,
                    vector<vector<long long>>& memo,
                    long long INF) {
        if (remaining == 0) return 0;
        if (i == (int)nums.size()) return INF;

        long long& ans = memo[i][remaining];
        if (ans != -1) return ans;

        // Skip index i
        ans = solve(nums, x, i + 1, remaining, cost, memo, INF);

        // Take a window starting at i
        if (i + x <= (int)nums.size()) {
            long long pick = cost[i] +
                solve(nums, x, i + x, remaining - 1, cost, memo, INF);
            ans = min(ans, pick);
        }

        return ans;
    }

    vector<long long> getMinOps(const vector<int>& nums, int x) {
        vector<long long> result;

        multiset<int> lower, upper;
        long long lowerSum = 0, upperSum = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            // Insert nums[i]
            if (lower.empty() || nums[i] <= *lower.rbegin()) {
                lower.insert(nums[i]);
                lowerSum += nums[i];
            } else {
                upper.insert(nums[i]);
                upperSum += nums[i];
            }

            // Remove the element leaving the window
            if (i >= x) {
                int out = nums[i - x];

                auto it = lower.find(out);
                if (it != lower.end()) {
                    lower.erase(it);
                    lowerSum -= out;
                } else {
                    it = upper.find(out);
                    upper.erase(it);
                    upperSum -= out;
                }
            }

            // Rebalance: lower has either the same number of elements
            // as upper, or exactly one more.
            if (lower.size() < upper.size()) {
                auto it = upper.begin();
                int value = *it;
                upper.erase(it);
                upperSum -= value;

                lower.insert(value);
                lowerSum += value;
            } else if (lower.size() - upper.size() > 1) {
                auto it = prev(lower.end());
                int value = *it;
                lower.erase(it);
                lowerSum -= value;

                upper.insert(value);
                upperSum += value;
            }

            // Record the cost once the window is full
            if (i >= x - 1) {
                long long median = *lower.rbegin();

                long long ops =
                    median * (long long)lower.size() - lowerSum +
                    upperSum - median * (long long)upper.size();

                result.push_back(ops);
            }
        }

        return result;
    }
};