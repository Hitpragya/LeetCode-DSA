class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int waysTwoStepsBefore = 1;
        int waysOneStepBefore = 2;

        for (int currentStep = 3; currentStep <= n; ++currentStep) {
            int currentWays = waysOneStepBefore + waysTwoStepsBefore;
            waysTwoStepsBefore = waysOneStepBefore;
            waysOneStepBefore = currentWays;
        }

        return waysOneStepBefore;
    }
};