class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int infinity = 1e9;

        vector<int> bestLength(n, infinity);

        int left = 0;
        int windowSum = 0;
        int minimumTotalLength = infinity;

        for (int right = 0; right < n; ++right) {
            windowSum += arr[right];

            while (windowSum > target) {
                windowSum -= arr[left];
                ++left;
            }

            if (windowSum == target) {
                int currentLength = right - left + 1;

                if (left > 0 && bestLength[left - 1] != infinity) {
                    minimumTotalLength = min(
                        minimumTotalLength,
                        bestLength[left - 1] + currentLength
                    );
                }

                bestLength[right] = currentLength;
            }

            if (right > 0) {
                bestLength[right] = min(bestLength[right], bestLength[right - 1]);
            }
        }

        return minimumTotalLength == infinity ? -1 : minimumTotalLength;
    }
};