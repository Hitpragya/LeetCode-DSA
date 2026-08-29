class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> valueIndexPairs;

        for (int index = 0; index < n; index++) {
            valueIndexPairs.push_back({nums[index], index});
        }

        sort(valueIndexPairs.begin(), valueIndexPairs.end());

        vector<int> result(n);
        int groupStart = 0;

        while (groupStart < n) {
            int groupEnd = groupStart;

            while (groupEnd + 1 < n &&
                   valueIndexPairs[groupEnd + 1].first - valueIndexPairs[groupEnd].first <= limit) {
                groupEnd++;
            }

            vector<int> indices;

            for (int position = groupStart; position <= groupEnd; position++) {
                indices.push_back(valueIndexPairs[position].second);
            }

            sort(indices.begin(), indices.end());

            for (int position = 0; position < indices.size(); position++) {
                result[indices[position]] = valueIndexPairs[groupStart + position].first;
            }

            groupStart = groupEnd + 1;
        }

        return result;
    }
};