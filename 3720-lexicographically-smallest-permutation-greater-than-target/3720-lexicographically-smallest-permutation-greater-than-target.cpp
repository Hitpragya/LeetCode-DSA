class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        array<int,26> freq{};
        for (char c : s) freq[c - 'a']++;

        vector<array<int,26>> freqBefore(n);
        int matchedLength = n;

        for (int i = 0; i < n; i++) {
            freqBefore[i] = freq;
            int t = target[i] - 'a';
            if (freq[t] > 0) {
                freq[t]--;
            } else {
                matchedLength = i;
                break;
            }
        }

        for (int pos = min(matchedLength, n - 1); pos >= 0; pos--) {
            array<int,26> avail = freqBefore[pos];
            int t = target[pos] - 'a';
            int chosen = -1;
            for (int c = t + 1; c < 26; c++) {
                if (avail[c] > 0) {
                    chosen = c;
                    break;
                }
            }
            if (chosen == -1) continue;

            avail[chosen]--;
            string answer = target.substr(0, pos);
            answer += char('a' + chosen);
            for (int c = 0; c < 26; c++) {
                while (avail[c] > 0) {
                    answer += char('a' + c);
                    avail[c]--;
                }
            }
            return answer;
        }
        return "";
    }
};