#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int currentMax = 0;

        for (int i = 0; i < n; ++i) {
            currentMax = max(currentMax, nums[i]);
            prefixGcd[i] = std::gcd(currentMax, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long result = 0;
        int left = 0;
        int right = n - 1;

        while (left < right) {
            result += std::gcd(prefixGcd[left], prefixGcd[right]);
            ++left;
            --right;
        }

        return result;
    }
};