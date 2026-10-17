class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> order(n);
        for (int i = 0; i < n; ++i) {
            int sum = 0, val = nums[i];
            while (val > 0) { sum += val % 10; val /= 10; }
            order[i] = {sum, nums[i]};
        }
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (order[a].first != order[b].first) return order[a].first < order[b].first;
            return order[a].second < order[b].second;
        });
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[idx[i]] = i;
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] || pos[i] == i) { visited[i] = true; continue; }
            int cycleLen = 0, j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = pos[j];
                ++cycleLen;
            }
            swaps += cycleLen - 1;
        }
        return swaps;
    }
};