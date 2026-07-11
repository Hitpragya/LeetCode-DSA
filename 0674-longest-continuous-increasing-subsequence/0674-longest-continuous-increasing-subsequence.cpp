#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int currentLength = 1;
        int maxLength = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++currentLength;
            } else {
                currentLength = 1;
            }
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }
        return maxLength;
    }
};