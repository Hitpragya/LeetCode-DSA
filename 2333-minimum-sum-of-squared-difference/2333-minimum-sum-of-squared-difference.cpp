class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> differences(n);
        int maximumDifference = 0;

        for (int index = 0; index < n; ++index) {
            differences[index] = abs(nums1[index] - nums2[index]);
            maximumDifference = max(maximumDifference, differences[index]);
        }

        long long totalOperations = static_cast<long long>(k1) + k2;

        long long low = 0, high = maximumDifference;
        while (low < high) {
            long long middle = low + (high - low) / 2;
            if (canAchieveLimit(differences, middle, totalOperations)) {
                high = middle;
            } else {
                low = middle + 1;
            }
        }

        long long answer = 0;
        long long remainingOperations = totalOperations;
        long long valuesAtLimit = 0;

        for (int difference : differences) {
            if (difference > low) {
                answer += low * low;
                remainingOperations -= difference - low;
                ++valuesAtLimit;
            } else {
                answer += static_cast<long long>(difference) * difference;
                if (difference == low) {
                    ++valuesAtLimit;
                }
            }
        }

        if (low > 0) {
            long long valuesToReduce = min(remainingOperations, valuesAtLimit);
            answer -= valuesToReduce * low * low;
            answer += valuesToReduce * (low - 1) * (low - 1);
        }

        return answer;
    }

private:
    bool canAchieveLimit(const vector<int>& differences, long long limit, long long totalOperations) {
        long long requiredOperations = 0;

        for (int difference : differences) {
            if (difference > limit) {
                requiredOperations += difference - limit;
                if (requiredOperations > totalOperations) {
                    return false;
                }
            }
        }

        return true;
    }
};