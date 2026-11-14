class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string formattedKey;
        int groupSize = 0;

        for (int index = s.size() - 1; index >= 0; index--) {
            if (s[index] == '-') {
                continue;
            }

            formattedKey.push_back(toupper(s[index]));
            groupSize++;

            if (groupSize == k) {
                formattedKey.push_back('-');
                groupSize = 0;
            }
        }

        reverse(formattedKey.begin(), formattedKey.end());

        if (!formattedKey.empty() && formattedKey.front() == '-') {
            formattedKey.erase(formattedKey.begin());
        }

        return formattedKey;
    }
};