class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> previous(k, 0);

        for (int number : nums) {
            int currentRemainder = number % k;
            vector<long long> current(k, 0);

            current[currentRemainder]++;

            for (int remainder = 0; remainder < k; remainder++) {
                int newRemainder = (remainder * currentRemainder) % k;
                current[newRemainder] += previous[remainder];
            }

            for (int remainder = 0; remainder < k; remainder++) {
                result[remainder] += current[remainder];
            }

            previous = current;
        }

        return result;
    }
};
