class Solution {
public:
    bool detectCapitalUse(string word) {
        int uppercaseCount = 0;

        for (char letter : word) {
            if (isupper(letter)) {
                uppercaseCount++;
            }
        }

        return uppercaseCount == 0 ||
               uppercaseCount == word.size() ||
               (uppercaseCount == 1 && isupper(word[0]));
    }
};