#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> pairSet;
        for (int j = 0; j < n; j++) {
            for (int k = j; k < n; k++) {
                int val = nums[j] ^ nums[k];
                pairSet.insert(val);
            }
        }
        unordered_set<int> tripletSet;
        for (int i = 0; i < n; i++) {
            for (int v : pairSet) {
                int x = nums[i] ^ v;
                tripletSet.insert(x);
            }
        }
        return (int)tripletSet.size();
    }
};