class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long separateCost = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        long long allBothCost = 1LL * costBoth * max(need1, need2);

        long long commonNeed = min(need1, need2);
        long long mixedCost = 1LL * commonNeed * costBoth;
        mixedCost += 1LL * (need1 - commonNeed) * cost1;
        mixedCost += 1LL * (need2 - commonNeed) * cost2;

        return min({separateCost, allBothCost, mixedCost});
    }
};