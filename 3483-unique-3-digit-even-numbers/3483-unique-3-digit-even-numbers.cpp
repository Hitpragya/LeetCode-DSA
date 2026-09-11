class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> frequency(10, 0);

        for (int digit : digits) {
            frequency[digit]++;
        }

        int validNumbers = 0;

        for (int number = 100; number <= 998; number += 2) {
            int hundreds = number / 100;
            int tens = (number / 10) % 10;
            int ones = number % 10;

            vector<int> required(10, 0);
            required[hundreds]++;
            required[tens]++;
            required[ones]++;

            bool canForm = true;

            for (int digit = 0; digit <= 9; digit++) {
                if (required[digit] > frequency[digit]) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                validNumbers++;
            }
        }

        return validNumbers;
    }
};