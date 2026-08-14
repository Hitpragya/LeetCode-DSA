class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> frequency(26, 0);
        int left = 0;
        int maximumLength = 0;

        for (int right = 0; right < s.size(); ++right) {
            ++frequency[s[right] - 'a'];

            while (frequency[s[right] - 'a'] > 2) {
                --frequency[s[left] - 'a'];
                ++left;
            }

            maximumLength = max(maximumLength, right - left + 1);
        }

        return maximumLength;
    }
};