class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using State = tuple<long long, int, int>;

        priority_queue<State, vector<State>, greater<State>> minHeap;
        vector<vector<int>> answer;

        int rows = min(static_cast<int>(nums1.size()), k);

        for (int i = 0; i < rows; i++) {
            minHeap.push({1LL * nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            answer.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                minHeap.push({1LL * nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return answer;
    }
};