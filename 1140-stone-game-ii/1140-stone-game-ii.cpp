class Solution {
    vector<int> suffixSum;
    vector<vector<int>> memo;
    int totalPiles;

    int solve(int index, int currentM) {
        if (index >= totalPiles) {
            return 0;
        }

        if (index + 2 * currentM >= totalPiles) {
            return suffixSum[index];
        }

        int& answer = memo[index][currentM];

        if (answer != -1) {
            return answer;
        }

        answer = 0;

        for (int pilesTaken = 1; pilesTaken <= 2 * currentM; ++pilesTaken) {
            int nextM = max(currentM, pilesTaken);
            int opponentStones = solve(index + pilesTaken, nextM);
            answer = max(answer, suffixSum[index] - opponentStones);
        }

        return answer;
    }

public:
    int stoneGameII(vector<int>& piles) {
        totalPiles = piles.size();
        suffixSum.assign(totalPiles + 1, 0);

        for (int index = totalPiles - 1; index >= 0; --index) {
            suffixSum[index] = piles[index] + suffixSum[index + 1];
        }

        memo.assign(totalPiles, vector<int>(totalPiles + 1, -1));

        return solve(0, 1);
    }
};