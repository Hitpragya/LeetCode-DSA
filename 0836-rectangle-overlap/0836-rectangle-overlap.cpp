class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int overlapLeft = max(rec1[0], rec2[0]);
        int overlapRight = min(rec1[2], rec2[2]);
        int overlapBottom = max(rec1[1], rec2[1]);
        int overlapTop = min(rec1[3], rec2[3]);

        return overlapLeft < overlapRight && overlapBottom < overlapTop;
    }
};