class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> chainLength;
        int longestChain = 0;

        for (int value : nums) {
            int previousLength = chainLength[value];

            chainLength[value] = max(chainLength[value], chainLength[value - 1] + 1);
            chainLength[value + 1] = max(chainLength[value + 1], previousLength + 1);

            longestChain = max({longestChain, chainLength[value], chainLength[value + 1]});
        }

        return longestChain;
    }
};