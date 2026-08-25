class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> presentMultiples;

        for (int value : nums) {
            if (value % k == 0) {
                presentMultiples.insert(value);
            }
        }

        for (int multiple = k; ; multiple += k) {
            if (!presentMultiples.count(multiple)) {
                return multiple;
            }
        }
    }
};