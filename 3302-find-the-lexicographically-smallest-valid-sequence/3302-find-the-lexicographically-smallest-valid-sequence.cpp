class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suffixMatch(n + 1, 0);
        int targetIndex = m - 1;

        for (int index = n - 1; index >= 0; --index) {
            suffixMatch[index] = suffixMatch[index + 1];

            if (targetIndex >= 0 && word1[index] == word2[targetIndex]) {
                ++suffixMatch[index];
                --targetIndex;
            }
        }

        vector<int> answer;
        answer.reserve(m);

        int matched = 0;
        bool modificationUsed = false;

        for (int index = 0; index < n && matched < m; ++index) {
            if (word1[index] == word2[matched]) {
                answer.push_back(index);
                ++matched;
            } else if (!modificationUsed &&
                       suffixMatch[index + 1] >= m - matched - 1) {
                answer.push_back(index);
                ++matched;
                modificationUsed = true;
            }
        }

        return matched == m ? answer : vector<int>{};
    }
}; 