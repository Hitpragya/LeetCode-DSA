class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int frequency[26] = {};

        for (char character : s) {
            frequency[character - 'a']++;
        }

        for (char character : t) {
            frequency[character - 'a']--;
        }

        for (int count : frequency) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};