class Solution {
public:
    bool checkString(string s) {
        for (int index = 0; index + 1 < static_cast<int>(s.size()); ++index) {
            if (s[index] == 'b' && s[index + 1] == 'a') {
                return false;
            }
        }

        return true;
    }
};