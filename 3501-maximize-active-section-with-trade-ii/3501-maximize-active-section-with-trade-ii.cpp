class SegmentTree {
    int size;
    vector<int> tree;

public:
    SegmentTree(const vector<int>& values) {
        size = 1;
        while (size < static_cast<int>(values.size())) {
            size <<= 1;
        }

        tree.assign(2 * size, 0);

        for (int i = 0; i < static_cast<int>(values.size()); ++i) {
            tree[size + i] = values[i];
        }

        for (int node = size - 1; node >= 1; --node) {
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int left, int right) const {
        if (left > right) {
            return 0;
        }

        left += size;
        right += size;
        int maximumValue = 0;

        while (left <= right) {
            if (left & 1) {
                maximumValue = max(maximumValue, tree[left++]);
            }

            if (!(right & 1)) {
                maximumValue = max(maximumValue, tree[right--]);
            }

            left >>= 1;
            right >>= 1;
        }

        return maximumValue;
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int totalOnes = count(s.begin(), s.end(), '1');

        vector<int> segmentStart;
        vector<int> segmentEnd;
        vector<int> segmentLength;
        vector<char> segmentValue;
        vector<int> segmentId(n);

        for (int start = 0; start < n;) {
            int end = start;

            while (end + 1 < n && s[end + 1] == s[start]) {
                ++end;
            }

            int id = segmentStart.size();
            segmentStart.push_back(start);
            segmentEnd.push_back(end);
            segmentLength.push_back(end - start + 1);
            segmentValue.push_back(s[start]);

            for (int position = start; position <= end; ++position) {
                segmentId[position] = id;
            }

            start = end + 1;
        }

        int segmentCount = segmentStart.size();
        vector<int> gain(segmentCount, 0);

        for (int i = 1; i + 1 < segmentCount; ++i) {
            if (segmentValue[i] == '1') {
                gain[i] = segmentLength[i - 1] + segmentLength[i + 1];
            }
        }

        SegmentTree maximumGainTree(gain);
        vector<int> answer;
        answer.reserve(queries.size());

        for (const vector<int>& query : queries) {
            int left = query[0];
            int right = query[1];
            int leftSegment = segmentId[left];
            int rightSegment = segmentId[right];
            int bestGain = 0;

            auto evaluateBoundaryCandidate = [&](int oneSegment) {
                if (oneSegment <= leftSegment || oneSegment >= rightSegment) {
                    return;
                }

                if (segmentValue[oneSegment] != '1') {
                    return;
                }

                int leftZeroGain =
                    segmentEnd[oneSegment - 1] -
                    max(left, segmentStart[oneSegment - 1]) + 1;

                int rightZeroGain =
                    min(right, segmentEnd[oneSegment + 1]) -
                    segmentStart[oneSegment + 1] + 1;

                bestGain = max(bestGain, leftZeroGain + rightZeroGain);
            };

            evaluateBoundaryCandidate(leftSegment + 1);
            evaluateBoundaryCandidate(rightSegment - 1);

            int interiorLeft = leftSegment + 2;
            int interiorRight = rightSegment - 2;

            bestGain = max(bestGain, maximumGainTree.query(interiorLeft, interiorRight));
            answer.push_back(totalOnes + bestGain);
        }

        return answer;
    }
};