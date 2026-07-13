#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string base = "123456789";
        vector<int> candidates;

        int n = base.size();
        for (int length = 2; length <= n; ++length) {
            for (int start = 0; start + length <= n; ++start) {
                string sub = base.substr(start, length);
                int value = stoi(sub);
                candidates.push_back(value);
            }
        }

        vector<int> result;
        for (int value : candidates) {
            if (value >= low && value <= high) {
                result.push_back(value);
            }
        }

        sort(result.begin(), result.end()); // Defensive sort
        return result;
    }
};