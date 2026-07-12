#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> count;
        unordered_map<int, int> firstIndex;
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < n; i++) {
            int value = nums[i];

            if (firstIndex.find(value) == firstIndex.end()) {
                firstIndex[value] = i;
            }

            lastIndex[value] = i;
            count[value]++;
        }

        int degree = 0;
        for (auto& entry : count) {
            degree = max(degree, entry.second);
        }

        int minLength = n;
        for (auto& entry : count) {
            int value = entry.first;
            int freq = entry.second;

            if (freq == degree) {
                int length = lastIndex[value] - firstIndex[value] + 1;
                minLength = min(minLength, length);
            }
        }

        return minLength;
    }
};