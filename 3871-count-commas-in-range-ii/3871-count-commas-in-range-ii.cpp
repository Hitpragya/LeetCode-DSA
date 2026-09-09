class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long groupStart = 1000;
        long long commasPerNumber = 1;

        while (groupStart <= n) {
            long long numbersInGroup = min(n - groupStart + 1, groupStart * 999);
            totalCommas += numbersInGroup * commasPerNumber;

            if (groupStart > n / 1000) {
                break;
            }

            groupStart *= 1000;
            ++commasPerNumber;
        }

        return totalCommas;
    }
};