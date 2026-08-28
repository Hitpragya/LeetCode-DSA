class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        cnt = [0] * 26

        for ch in s:
            cnt[ord(ch) - ord('a')] += 1

        # Check whether a palindrome is possible
        mid = ""

        for i in range(26):
            if cnt[i] % 2:
                if mid:
                    return ""
                mid = chr(ord('a') + i)
                cnt[i] -= 1

        n = len(s)
        half = n // 2

        # Try to keep the first half equal to target's first half
        # cnt now represents pairs available for the left half.
        for ch in target[:half]:
            cnt[ord(ch) - ord('a')] -= 2

        # Number of characters for which we don't have enough copies
        negative = 0

        # Largest character currently available
        largest = -1

        for i in range(26):
            if cnt[i] < 0:
                negative += 1
            elif cnt[i] > 0:
                largest = max(largest, i)

        # Case 1:
        # We can make target's entire left half.
        # Check whether the corresponding palindrome is already > target.
        if negative == 0:
            left = target[:half]
            candidate = left + mid + left[::-1]

            if candidate > target:
                return candidate

        # Case 2:
        # Find the rightmost position where we can make
        # target[i] slightly larger.
        for i in range(half - 1, -1, -1):

            x = ord(target[i]) - ord('a')

            # Give back the pair used by target[i]
            cnt[x] += 2

            if cnt[x] == 0:
                negative -= 1
            elif cnt[x] == 2:
                largest = max(largest, x)

            # Prefix target[:i] must be possible,
            # and we need some available character > target[i].
            if negative > 0 or largest <= x:
                continue

            # Find smallest available character > target[i]
            j = x + 1

            while cnt[j] == 0:
                j += 1

            # Use this character as the first larger position
            cnt[j] -= 2

            # Build the left half
            left = list(target[:i])
            left.append(chr(ord('a') + j))

            # Fill remaining positions with smallest characters
            for k in range(26):
                left.extend([chr(ord('a') + k)] * (cnt[k] // 2))

            left = ''.join(left)

            # Build palindrome
            return left + mid + left[::-1]

        return ""