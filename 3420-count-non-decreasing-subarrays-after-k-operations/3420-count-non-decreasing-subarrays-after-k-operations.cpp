class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int LOG = 20;

        vector<int> nxt(n, n), st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            if (!st.empty())
                nxt[i] = st.back();

            st.push_back(i);
        }

        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> sum(LOG, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            sum[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i <= n; i++) {
                int mid = up[j - 1][i];
                up[j][i] = up[j - 1][mid];
                sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
            }
        }

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        auto cost = [&](int l, int r) {
            int cur = l;
            long long s = 0;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][cur] <= r) {
                    s += sum[j][cur];
                    cur = up[j][cur];
                }
            }

            s += 1LL * nums[cur] * (r - cur + 1);

            return s - (pref[r + 1] - pref[l]);
        };

        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            while (l <= r && cost(l, r) > k)
                l++;

            ans += r - l + 1;
        }

        return ans;
    }
};