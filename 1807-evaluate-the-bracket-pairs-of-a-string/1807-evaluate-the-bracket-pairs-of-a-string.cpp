class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> values;

        for (const vector<string>& pair : knowledge) {
            values[pair[0]] = pair[1];
        }

        string result;
        result.reserve(s.size());

        for (int index = 0; index < s.size(); ++index) {
            if (s[index] != '(') {
                result += s[index];
                continue;
            }

            string key;

            while (s[++index] != ')') {
                key += s[index];
            }

            if (values.count(key)) {
                result += values[key];
            } else {
                result += '?';
            }
        }

        return result;
    }
};