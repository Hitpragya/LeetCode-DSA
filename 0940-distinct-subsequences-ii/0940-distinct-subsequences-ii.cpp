class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1'000'000'007;
        vector<long long> endingWith(26, 0);
        long long total = 1;

        for (char character : s) {
            int index = character - 'a';
            long long previousTotal = total;

            total = (2 * total - endingWith[index] + MOD) % MOD;
            endingWith[index] = previousTotal;
        }

        return (total - 1 + MOD) % MOD;
    }
};