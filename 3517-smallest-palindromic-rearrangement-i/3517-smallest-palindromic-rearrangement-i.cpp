class Solution {
public:
    string smallestPalindrome(string s) {
        array<int, 26> frequency{};

        for (char character : s) {
            frequency[character - 'a']++;
        }

        string leftHalf;
        char middleCharacter = '\0';

        for (int index = 0; index < 26; index++) {
            leftHalf.append(frequency[index] / 2, char('a' + index));

            if (frequency[index] % 2 == 1) {
                middleCharacter = char('a' + index);
            }
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        return leftHalf + (middleCharacter == '\0' ? "" : string(1, middleCharacter)) + rightHalf;
    }
};