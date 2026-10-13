class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;
        squares.reserve(nums.size());

        long long totalSum = 0;

        for (int value : nums) {
            long long square = 1LL * value * value;
            squares.push_back(square);
            totalSum += square;
        }

        int negativeCount = nums.size() / 2;

        nth_element(
            squares.begin(),
            squares.begin() + negativeCount,
            squares.end()
        );

        long long negativeSum = accumulate(
            squares.begin(),
            squares.begin() + negativeCount,
            0LL
        );

        return totalSum - 2 * negativeSum;
    }
};