class Solution {
    struct Interval {
        long long start;
        long long end;
        long long weight;
        int index;
    };

    struct State {
        long long score;
        vector<int> indices;
    };

    State better(const State& first, const State& second) {
        if (first.score != second.score) {
            return first.score > second.score ? first : second;
        }
        return first.indices < second.indices ? first : second;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> sortedIntervals;

        for (int i = 0; i < n; ++i) {
            sortedIntervals.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(sortedIntervals.begin(), sortedIntervals.end(),
             [](const Interval& first, const Interval& second) {
                 if (first.end != second.end) {
                     return first.end < second.end;
                 }
                 return first.start < second.start;
             });

        vector<long long> endTimes(n);
        for (int i = 0; i < n; ++i) {
            endTimes[i] = sortedIntervals[i].end;
        }

        vector<int> previousCount(n);
        for (int i = 0; i < n; ++i) {
            previousCount[i] = lower_bound(
                endTimes.begin(),
                endTimes.begin() + i,
                sortedIntervals[i].start
            ) - endTimes.begin();
        }

        vector<vector<State>> dp(5, vector<State>(n + 1, {0, {}}));

        for (int count = 1; count <= 4; ++count) {
            for (int i = 1; i <= n; ++i) {
                dp[count][i] = dp[count][i - 1];

                const Interval& current = sortedIntervals[i - 1];
                State take = dp[count - 1][previousCount[i - 1]];
                take.score += current.weight;
                take.indices.push_back(current.index);
                sort(take.indices.begin(), take.indices.end());

                dp[count][i] = better(dp[count][i], take);
            }
        }

        return dp[4][n].indices;
    }
};