class Solution {
public:
    int minimumPushes(string word) {
        array<int, 26> frequency{};

        for (char character : word) {
            frequency[character - 'a']++;
        }

        sort(frequency.rbegin(), frequency.rend());

        int minimumPushes = 0;

        for (int index = 0; index < 26; index++) {
            int pressesRequired = index / 8 + 1;
            minimumPushes += frequency[index] * pressesRequired;
        }

        return minimumPushes;
    }
};