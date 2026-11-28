class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt(n + 1, 0), gain(n + 1, 0);
        int minPrice = INT_MAX;

        for (auto &x : items) {
            cnt[x[0]]++;
            minPrice = min(minPrice, x[1]);
        }

        for (int f = 1; f <= n; f++) {
            for (int j = f; j <= n; j += f)
                gain[f] += cnt[j];

            gain[f]--;
        }

        vector<pair<int, int>> deals;

        for (auto &x : items) {
            int f = x[0], p = x[1];

            if (gain[f] > 0 && p < 2LL * minPrice)
                deals.push_back({p, gain[f]});
        }

        sort(deals.begin(), deals.end());

        long long ans = 0;
        long long rem = budget;

        for (auto &d : deals) {
            long long take = min((long long)d.second, rem / d.first);
            ans += 2 * take;
            rem -= take * d.first;
        }

        ans += rem / minPrice;

        return (int)ans;
    }
};