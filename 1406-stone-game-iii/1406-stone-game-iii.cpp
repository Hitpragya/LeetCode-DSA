class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int nextOne = 0;
        int nextTwo = 0;
        int nextThree = 0;

        for (int index = stoneValue.size() - 1; index >= 0; --index) {
            int takenSum = 0;
            int bestDifference = INT_MIN;

            takenSum += stoneValue[index];
            bestDifference = max(bestDifference, takenSum - nextOne);

            if (index + 1 < stoneValue.size()) {
                takenSum += stoneValue[index + 1];
                bestDifference = max(bestDifference, takenSum - nextTwo);
            }

            if (index + 2 < stoneValue.size()) {
                takenSum += stoneValue[index + 2];
                bestDifference = max(bestDifference, takenSum - nextThree);
            }

            nextThree = nextTwo;
            nextTwo = nextOne;
            nextOne = bestDifference;
        }

        if (nextOne > 0) return "Alice";
        if (nextOne < 0) return "Bob";
        return "Tie";
    }
};