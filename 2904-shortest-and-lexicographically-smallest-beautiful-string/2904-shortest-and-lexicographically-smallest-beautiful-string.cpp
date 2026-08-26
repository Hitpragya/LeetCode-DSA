class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int onesCount = 0;
        int bestStart = -1;
        int shortestLength = s.size() + 1;

        for (int right = 0; right < s.size(); ++right) {
            if (s[right] == '1') {
                ++onesCount;
            }

            while (onesCount == k) {
                int currentLength = right - left + 1;

                if (currentLength < shortestLength ||
                    (currentLength == shortestLength &&
                     s.compare(left, currentLength, s, bestStart, shortestLength) < 0)) {
                    bestStart = left;
                    shortestLength = currentLength;
                }

                if (s[left] == '1') {
                    --onesCount;
                }

                ++left;
            }
        }

        if (bestStart == -1) {
            return "";
        }

        return s.substr(bestStart, shortestLength);
    }
};