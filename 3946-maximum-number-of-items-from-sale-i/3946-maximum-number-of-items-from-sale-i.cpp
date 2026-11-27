class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        constexpr int maxFactor = 1500;
        vector<int> exactCount(maxFactor + 1, 0);

        for (const auto& item : items) {
            ++exactCount[item[0]];
        }

        vector<int> multipleCount(maxFactor + 1, 0);
        for (int factor = 1; factor <= maxFactor; ++factor) {
            for (int multiple = factor; multiple <= maxFactor; multiple += factor) {
                multipleCount[factor] += exactCount[multiple];
            }
        }

        vector<int> best(budget + 1, 0);

        for (const auto& item : items) {
            int price = item[1];
            int firstCopyGain = multipleCount[item[0]];

            vector<int> next = best;

            for (int money = price; money <= budget; ++money) {
                next[money] = max(next[money], best[money - price] + firstCopyGain);
                next[money] = max(next[money], next[money - price] + 1);
            }

            best = move(next);
        }

        return best[budget];
    }
};