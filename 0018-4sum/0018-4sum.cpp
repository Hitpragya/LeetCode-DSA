#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n < 4) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                long long twoSumTarget = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long currentTwoSum = (long long)nums[left] + nums[right];

                    if (currentTwoSum < twoSumTarget) {
                        ++left;
                    } else if (currentTwoSum > twoSumTarget) {
                        --right;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        int lastLeftValue = nums[left];
                        int lastRightValue = nums[right];

                        while (left < right && nums[left] == lastLeftValue) {
                            ++left;
                        }
                        while (left < right && nums[right] == lastRightValue) {
                            --right;
                        }
                    }
                }
            }
        }

        return result;
    }
};