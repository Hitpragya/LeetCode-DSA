#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < (int)arr.size(); ++i) {
            int allowedValue = arr[i - 1] + 1;
            if (arr[i] > allowedValue) {
                arr[i] = allowedValue;
            }
        }
        return arr.back();
    }
};