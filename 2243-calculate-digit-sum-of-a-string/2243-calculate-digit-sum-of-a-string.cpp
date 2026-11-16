class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string next;
            next.reserve(s.size());

            int chunkSum = 0;
            int digitsInChunk = 0;

            for (char currentChar : s) {
                chunkSum += currentChar - '0';
                ++digitsInChunk;

                if (digitsInChunk == k) {
                    next += to_string(chunkSum);
                    chunkSum = 0;
                    digitsInChunk = 0;
                }
            }

            if (digitsInChunk > 0) {
                next += to_string(chunkSum);
            }

            s = move(next);
        }

        return s;
    }
};