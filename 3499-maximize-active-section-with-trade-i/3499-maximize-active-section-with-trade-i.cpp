class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int activeSections = count(s.begin(), s.end(), '1');
        string augmented = "1" + s + "1";
        int maximumGain = 0;
        int leftZeroLength = 0;
        int index = 0;

        while (index < augmented.size()) {
            if (augmented[index] == '0') {
                int start = index;
                while (index < augmented.size() && augmented[index] == '0') {
                    ++index;
                }
                leftZeroLength = index - start;
            } else {
                while (index < augmented.size() && augmented[index] == '1') {
                    ++index;
                }

                if (leftZeroLength > 0 && index < augmented.size() && augmented[index] == '0') {
                    int start = index;
                    while (index < augmented.size() && augmented[index] == '0') {
                        ++index;
                    }
                    int rightZeroLength = index - start;
                    maximumGain = max(maximumGain, leftZeroLength + rightZeroLength);
                    leftZeroLength = rightZeroLength;
                }
            }
        }

        return activeSections + maximumGain;
    }
};