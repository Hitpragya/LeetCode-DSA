class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maximumValue = *max_element(nums.begin(), nums.end());

        vector<int> frequency(maximumValue + 1, 0);
        for (int value : nums) {
            frequency[value]++;
        }

        vector<long long> exactGcdCount(maximumValue + 1, 0);

        for (int gcdValue = maximumValue; gcdValue >= 1; --gcdValue) {
            long long divisibleCount = 0;

            for (int multiple = gcdValue; multiple <= maximumValue; multiple += gcdValue) {
                divisibleCount += frequency[multiple];
            }

            exactGcdCount[gcdValue] = divisibleCount * (divisibleCount - 1) / 2;

            for (int multiple = gcdValue * 2; multiple <= maximumValue; multiple += gcdValue) {
                exactGcdCount[gcdValue] -= exactGcdCount[multiple];
            }
        }

        vector<long long> prefixCount(maximumValue + 1, 0);
        for (int gcdValue = 1; gcdValue <= maximumValue; ++gcdValue) {
            prefixCount[gcdValue] = prefixCount[gcdValue - 1] + exactGcdCount[gcdValue];
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (long long query : queries) {
            int gcdValue = lower_bound(prefixCount.begin() + 1, prefixCount.end(), query + 1) - prefixCount.begin();
            answer.push_back(gcdValue);
        }

        return answer;
    }
};