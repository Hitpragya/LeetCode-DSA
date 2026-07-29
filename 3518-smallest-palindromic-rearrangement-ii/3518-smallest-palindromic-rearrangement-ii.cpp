#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long countPermutations(const array<int, 26>& frequency, int length, long long limit) {
        long long ways = 1;
        int processed = 0;

        for (int letter = 0; letter < 26; ++letter) {
            for (int occurrence = 1; occurrence <= frequency[letter]; ++occurrence) {
                long long numerator = processed + occurrence;
                long long denominator = occurrence;

                long long commonFactor = gcd(numerator, denominator);
                numerator /= commonFactor;
                denominator /= commonFactor;

                commonFactor = gcd(ways, denominator);
                ways /= commonFactor;
                denominator /= commonFactor;

                if (ways > limit / numerator) {
                    return limit;
                }

                ways *= numerator;

                if (ways >= limit) {
                    return limit;
                }
            }

            processed += frequency[letter];
        }

        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        array<int, 26> frequency{};
        string middle;

        for (char character : s) {
            ++frequency[character - 'a'];
        }

        for (int letter = 0; letter < 26; ++letter) {
            frequency[letter] /= 2;

            if (s.size() % 2 == 1 && count(s.begin(), s.end(), char('a' + letter)) % 2 == 1) {
                middle = char('a' + letter);
            }
        }

        int remainingLength = s.size() / 2;
        string leftHalf;
        leftHalf.reserve(remainingLength);

        while (remainingLength > 0) {
            bool selected = false;

            for (int letter = 0; letter < 26; ++letter) {
                if (frequency[letter] == 0) {
                    continue;
                }

                --frequency[letter];

                long long waysWithLetter = countPermutations(frequency, remainingLength - 1, k);

                if (waysWithLetter < k) {
                    k -= waysWithLetter;
                    ++frequency[letter];
                } else {
                    leftHalf.push_back(char('a' + letter));
                    --remainingLength;
                    selected = true;
                    break;
                }
            }

            if (!selected) {
                return "";
            }
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        return leftHalf + middle + rightHalf;
    }
};