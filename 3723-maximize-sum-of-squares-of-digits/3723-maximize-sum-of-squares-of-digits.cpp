class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        int nines = sum / 9;
        int remainder = sum % 9;

        if (nines == num && remainder > 0) return "";

        string result;
        result.reserve(num);

        result.append(nines, '9');

        if (remainder > 0) {
            result.push_back('0' + remainder);
        }

        result.append(num - result.size(), '0');

        return result;
    }
};