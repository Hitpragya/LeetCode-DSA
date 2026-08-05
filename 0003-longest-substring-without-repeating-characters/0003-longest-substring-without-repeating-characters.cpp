class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeenIndex(256, -1);
        int windowStart = 0;
        int maxLength = 0;

        for (int windowEnd = 0; windowEnd < static_cast<int>(s.size()); ++windowEnd) {
            char currentChar = s[windowEnd];

            if (lastSeenIndex[currentChar] >= windowStart) {
                windowStart = lastSeenIndex[currentChar] + 1;
            }

            lastSeenIndex[currentChar] = windowEnd;

            int currentWindowLength = windowEnd - windowStart + 1;
            if (currentWindowLength > maxLength) {
                maxLength = currentWindowLength;
            }
        }

        return maxLength;
    }
};