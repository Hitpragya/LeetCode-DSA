class Solution {
public:
    int reverseDegree(string s) {
        int reverseDegree = 0;

        for (int index = 0; index < s.size(); index++) {
            int reverseAlphabetValue = 26 - (s[index] - 'a');
            int stringPosition = index + 1;

            reverseDegree += reverseAlphabetValue * stringPosition;
        }

        return reverseDegree;
    }
};