class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int distanceValue = 0;

        for (int value : arr1) {
            auto upperBound = lower_bound(arr2.begin(), arr2.end(), value);

            bool hasCloseElement = false;

            if (upperBound != arr2.end() && *upperBound - value <= d) {
                hasCloseElement = true;
            }

            if (upperBound != arr2.begin() && value - *prev(upperBound) <= d) {
                hasCloseElement = true;
            }

            if (!hasCloseElement) {
                ++distanceValue;
            }
        }

        return distanceValue;
    }
};