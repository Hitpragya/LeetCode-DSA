#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        if (n == 0) {
            return {};
        }

        vector<int> sortedValues = arr;
        sort(sortedValues.begin(), sortedValues.end());

        unordered_map<int, int> valueToRank;
        int currentRank = 1;

        valueToRank[sortedValues[0]] = currentRank;

        for (int i = 1; i < n; i++) {
            if (sortedValues[i] != sortedValues[i - 1]) {
                currentRank++;
                valueToRank[sortedValues[i]] = currentRank;
            }
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = valueToRank[arr[i]];
        }

        return result;
    }
};