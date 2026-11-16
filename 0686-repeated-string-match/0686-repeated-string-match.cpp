class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int minimumRepetitions = (b.size() + a.size() - 1) / a.size();
        string repeated;

        for (int repetition = 0; repetition < minimumRepetitions; ++repetition) {
            repeated += a;
        }

        if (repeated.find(b) != string::npos) {
            return minimumRepetitions;
        }

        repeated += a;

        if (repeated.find(b) != string::npos) {
            return minimumRepetitions + 1;
        }

        return -1;
    }
};