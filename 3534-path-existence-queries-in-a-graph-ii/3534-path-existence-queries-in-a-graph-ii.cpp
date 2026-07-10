class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            if (nums[a] == nums[b]) return a < b;
            return nums[a] < nums[b];
        });

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[order[i]] = i;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        int left = 0;
        for (int i = 0; i < n; i++) {
            while (nums[order[i]] - nums[order[left]] > maxDiff) {
                left++;
            }
            up[0][i] = left;
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int a = pos[q[0]];
            int b = pos[q[1]];

            if (a < b) swap(a, b);
            if (a == b) {
                ans.push_back(0);
                continue;
            }

            int curr = a;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][curr] > b) {
                    curr = up[k][curr];
                    steps += 1 << k;
                }
            }

            if (up[0][curr] > b) ans.push_back(-1);
            else ans.push_back(steps + 1);
        }

        return ans;
    }
};