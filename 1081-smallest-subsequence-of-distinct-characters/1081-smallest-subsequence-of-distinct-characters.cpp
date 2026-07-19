class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> remainingCount(26, 0);
        vector<bool> inResult(26, false);
        string result;

        for (char character : s) {
            ++remainingCount[character - 'a'];
        }

        for (char character : s) {
            --remainingCount[character - 'a'];

            if (inResult[character - 'a']) {
                continue;
            }

            while (!result.empty() &&
                   result.back() > character &&
                   remainingCount[result.back() - 'a'] > 0) {
                inResult[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(character);
            inResult[character - 'a'] = true;
        }

        return result;
    }
};