class Solution {
public:
    int minimumPushes(string word) {
        int minimumPushes = 0;

        for (int index = 0; index < word.length(); ++index) {
            minimumPushes += index / 8 + 1;
        }

        return minimumPushes;
    }
};