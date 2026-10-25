class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int maxPrice = 100000;
        vector<int> priceFrequency(maxPrice + 1, 0);

        for (int cost : costs) {
            priceFrequency[cost]++;
        }

        int iceCreamsBought = 0;

        for (int price = 1; price <= maxPrice; price++) {
            if (coins < price) break;

            int affordable = min(priceFrequency[price], coins / price);
            iceCreamsBought += affordable;
            coins -= affordable * price;
        }

        return iceCreamsBought;
    }
};