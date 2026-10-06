class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_unmatched = 0;
        int close_needed = 0;

        for (char ch : s) {
            if (ch == '(') {
                open_unmatched++;
            } else {
                if (open_unmatched > 0) {
                    open_unmatched--;
                } else {
                    close_needed++;
                }
            }
        }

        return open_unmatched + close_needed;
    }
};