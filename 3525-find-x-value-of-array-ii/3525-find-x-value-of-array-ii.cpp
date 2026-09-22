class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n + 1, 1); // pref[i] = product of nums[0..i-1] mod k
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = (1LL * pref[i] * (nums[i] % k)) % k;
        }

        // For each remainder r, cnt[r][i] = how many j in [i, n-1] have
        // (pref[j+1] * inv(pref[i]) % k) == r
        // Instead of inverses, we directly store counts of pref-remainders per suffix.
        // Since k is tiny, we can just recompute counts per query over the suffix.
        // To avoid O(n) per query, we use frequency arrays and update them incrementally.

        // Simpler approach that passes: for each query, iterate from start to n-1
        // and count remainders. Because k <= 5 and total operations are limited,
        // many solutions with O(n) per query still TLE, so we must be smarter.

        // Correct efficient approach:
        // Maintain for each position i and each remainder r:
        // how many prefixes of nums[i..n-1] have product % k == r.
        // This can be done by processing from right to left once and storing
        // dp[i][r] = count of prefixes of suffix starting at i with product % k == r.
        // Then each query is O(1) after point updates + some recomputation.

        // Given complexity of implementing a fully optimal structure here,
        // the safest is to follow the editorial’s segment-tree but with very
        // light Node and merge. Your current code is close; main TLE causes:
        // - Using vector<int> count inside Node causes many allocations.
        // - Creating new Node objects constantly in query/merge.

        // Optimized version: use fixed-size array in Node and avoid allocations.

        struct Node {
            int prod;
            int cnt[5]; // k <= 5

            Node() : prod(1) {
                for (int i = 0; i < 5; ++i) cnt[i] = 0;
            }
        };

        int K = k;
        int N = n;
        vector<Node> seg(4 * N);

        auto merge = [&](const Node& L, const Node& R) {
            Node res;
            res.prod = (L.prod * R.prod) % K;
            for (int i = 0; i < K; ++i) res.cnt[i] = 0;

            // Prefixes entirely in L
            for (int i = 0; i < K; ++i) {
                res.cnt[i] += L.cnt[i];
            }
            // Prefixes that take all L and then some prefix of R
            for (int i = 0; i < K; ++i) {
                int nr = (L.prod * i) % K;
                res.cnt[nr] += R.cnt[i];
            }
            return res;
        };

        function<void(int,int,int)> build = [&](int idx, int l, int r) {
            if (l == r) {
                int rem = nums[l] % K;
                seg[idx].prod = rem;
                for (int i = 0; i < K; ++i) seg[idx].cnt[i] = 0;
                seg[idx].cnt[rem] = 1;
                return;
            }
            int mid = (l + r) / 2;
            build(idx * 2, l, mid);
            build(idx * 2 + 1, mid + 1, r);
            seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
        };

        function<void(int,int,int,int,int)> update =
            [&](int idx, int l, int r, int pos, int val) {
            if (l == r) {
                int rem = val % K;
                seg[idx].prod = rem;
                for (int i = 0; i < K; ++i) seg[idx].cnt[i] = 0;
                seg[idx].cnt[rem] = 1;
                return;
            }
            int mid = (l + r) / 2;
            if (pos <= mid) update(idx * 2, l, mid, pos, val);
            else update(idx * 2 + 1, mid + 1, r, pos, val);
            seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
        };

        function<Node(int,int,int,int,int)> query =
            [&](int idx, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) return seg[idx];
            int mid = (l + r) / 2;
            if (qr <= mid) return query(idx * 2, l, mid, ql, qr);
            if (ql > mid) return query(idx * 2 + 1, mid + 1, r, ql, qr);
            Node L = query(idx * 2, l, mid, ql, qr);
            Node R = query(idx * 2 + 1, mid + 1, r, ql, qr);
            return merge(L, R);
        };

        build(1, 0, N - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &qy : queries) {
            int id = qy[0];
            int val = qy[1];
            int st = qy[2];
            int target = qy[3];

            update(1, 0, N - 1, id, val);
            Node res = query(1, 0, N - 1, st, N - 1);
            ans.push_back(res.cnt[target]);
        }

        return ans;
    }
};