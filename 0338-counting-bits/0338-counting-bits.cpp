class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bitCounts(n + 1, 0);

        for (int number = 1; number <= n; ++number) {
            bitCounts[number] = bitCounts[number >> 1] + (number & 1);
        }

        return bitCounts;
    }
};