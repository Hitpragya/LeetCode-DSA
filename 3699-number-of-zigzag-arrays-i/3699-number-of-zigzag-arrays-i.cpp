class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1'000'000'007;
        int valueCount = r - l + 1;

        vector<int> up(valueCount);
        vector<int> down(valueCount);

        for (int index = 0; index < valueCount; ++index) {
            up[index] = index;
            down[index] = valueCount - 1 - index;
        }

        for (int length = 3; length <= n; ++length) {
            vector<int> nextUp(valueCount);
            vector<int> nextDown(valueCount);

            long long smallerSum = 0;

            for (int index = 0; index < valueCount; ++index) {
                nextUp[index] = smallerSum;
                smallerSum += down[index];

                if (smallerSum >= MOD) {
                    smallerSum -= MOD;
                }
            }

            long long greaterSum = 0;

            for (int index = valueCount - 1; index >= 0; --index) {
                nextDown[index] = greaterSum;
                greaterSum += up[index];

                if (greaterSum >= MOD) {
                    greaterSum -= MOD;
                }
            }

            up.swap(nextUp);
            down.swap(nextDown);
        }

        long long answer = 0;

        for (int index = 0; index < valueCount; ++index) {
            answer += up[index] + down[index];

            if (answer >= MOD) {
                answer %= MOD;
            }
        }

        return static_cast<int>(answer % MOD);
    }
};