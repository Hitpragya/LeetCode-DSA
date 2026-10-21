class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        char minChar = *min_element(s.begin(), s.end());
        char maxChar = *max_element(s.begin(), s.end());

        if (s.front() == minChar || s.back() == maxChar) {
            return 1;
        }

        bool minCharInPrefix = false;
        bool maxCharInSuffix = false;

        for (int index = 0; index < n - 1; index++) {
            if (s[index] == minChar) {
                minCharInPrefix = true;
            }
        }

        for (int index = 1; index < n; index++) {
            if (s[index] == maxChar) {
                maxCharInSuffix = true;
            }
        }

        if (!minCharInPrefix && !maxCharInSuffix) {
            return 3;
        }

        return 2;
    }
};