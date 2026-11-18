class Solution {
public:
    int minChanges(string s) {
        int changes = 0;

        for (int index = 0; index < s.size(); index += 2) {
            if (s[index] != s[index + 1]) {
                ++changes;
            }
        }

        return changes;
    }
};