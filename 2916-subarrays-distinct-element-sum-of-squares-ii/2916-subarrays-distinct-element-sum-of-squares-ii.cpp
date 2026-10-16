class Solution {
    vector<long long> sum, sq, lazy;
    int n;
    static constexpr long long MOD = 1'000'000'007;

    void apply(int node, int left, int right, long long add) {
        sq[node] = (sq[node] + 2 * add * sum[node] + add * add % MOD * (right - left + 1)) % MOD;
        sum[node] = (sum[node] + add * (right - left + 1)) % MOD;
        lazy[node] = (lazy[node] + add) % MOD;
    }

    void pushDown(int node, int left, int right) {
        if (lazy[node] == 0) return;
        int mid = (left + right) / 2;
        apply(2 * node, left, mid, lazy[node]);
        apply(2 * node + 1, mid + 1, right, lazy[node]);
        lazy[node] = 0;
    }

    void update(int node, int left, int right, int l, int r) {
        if (r < left || right < l) return;
        if (l <= left && right <= r) {
            apply(node, left, right, 1);
            return;
        }
        pushDown(node, left, right);
        int mid = (left + right) / 2;
        update(2 * node, left, mid, l, r);
        update(2 * node + 1, mid + 1, right, l, r);
        sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
        sq[node] = (sq[2 * node] + sq[2 * node + 1]) % MOD;
    }

    long long querySq(int node, int left, int right, int l, int r) {
        if (r < left || right < l) return 0;
        if (l <= left && right <= r) return sq[node];
        pushDown(node, left, right);
        int mid = (left + right) / 2;
        return (querySq(2 * node, left, mid, l, r) +
                querySq(2 * node + 1, mid + 1, right, l, r)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int right = 0; right < n; right++) {
            int prev = last[nums[right]];
            update(1, 0, n - 1, prev + 1, right);

            ans = (ans + querySq(1, 0, n - 1, 0, right)) % MOD;
            last[nums[right]] = right;
        }

        return ans;
    }
};