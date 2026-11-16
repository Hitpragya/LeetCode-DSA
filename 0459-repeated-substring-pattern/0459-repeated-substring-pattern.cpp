class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int stringLength = s.size();
        vector<int> longestPrefixSuffix(stringLength, 0);

        int previousMatchLength = 0;

        for (int currentIndex = 1; currentIndex < stringLength; currentIndex++) {
            while (previousMatchLength > 0 && s[currentIndex] != s[previousMatchLength]) {
                previousMatchLength = longestPrefixSuffix[previousMatchLength - 1];
            }

            if (s[currentIndex] == s[previousMatchLength]) {
                previousMatchLength++;
            }

            longestPrefixSuffix[currentIndex] = previousMatchLength;
        }

        int longestBorder = longestPrefixSuffix[stringLength - 1];
        int patternLength = stringLength - longestBorder;

        return longestBorder > 0 && stringLength % patternLength == 0;
    }
};