class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        array<int, 3> remainderCount = {0, 0, 0};

        for (int stone : stones) {
            remainderCount[stone % 3]++;
        }

        int countZero = remainderCount[0];
        int countOne = remainderCount[1];
        int countTwo = remainderCount[2];

        if (countZero % 2 == 0) {
            return countOne > 0 && countTwo > 0;
        }

        return abs(countOne - countTwo) > 2;
    }
};