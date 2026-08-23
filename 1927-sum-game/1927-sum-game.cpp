class Solution {
public:
    bool sumGame(string num) {
        int half = num.size() / 2;
        int leftSum = 0;
        int rightSum = 0;
        int leftQuestions = 0;
        int rightQuestions = 0;

        for (int index = 0; index < num.size(); index++) {
            if (num[index] == '?') {
                if (index < half) {
                    leftQuestions++;
                } else {
                    rightQuestions++;
                }
            } else {
                if (index < half) {
                    leftSum += num[index] - '0';
                } else {
                    rightSum += num[index] - '0';
                }
            }
        }

        if ((leftQuestions + rightQuestions) % 2 == 1) {
            return true;
        }

        return 2 * (leftSum - rightSum) != 9 * (rightQuestions - leftQuestions);
    }
};