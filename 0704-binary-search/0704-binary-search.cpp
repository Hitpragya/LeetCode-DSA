#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = 0;
        int low = nums.size() - 1;

        while (high <= low) {
            int mid = high + (low - high) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                high = mid + 1;
            } else {
                low = mid - 1;
            }
        }

        return -1;
    }
};