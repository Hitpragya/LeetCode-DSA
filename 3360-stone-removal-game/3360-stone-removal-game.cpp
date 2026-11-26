class Solution {
public:
    bool canAliceWin(int n) {
        int stonesRemaining = n;
        int requiredStones = 10;
        bool aliceTurn = true;

        while (stonesRemaining >= requiredStones) {
            stonesRemaining -= requiredStones;
            --requiredStones;
            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
};