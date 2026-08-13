class Solution {
    struct Node {
        char leftCharacter;
        char rightCharacter;
        int segmentLength;
        int prefixLength;
        int suffixLength;
        int bestLength;
    };

    vector<Node> tree;
    string text;

    Node mergeNodes(const Node& leftNode, const Node& rightNode) {
        Node merged;
        merged.leftCharacter = leftNode.leftCharacter;
        merged.rightCharacter = rightNode.rightCharacter;
        merged.segmentLength = leftNode.segmentLength + rightNode.segmentLength;

        merged.prefixLength = leftNode.prefixLength;
        if (leftNode.prefixLength == leftNode.segmentLength &&
            leftNode.rightCharacter == rightNode.leftCharacter) {
            merged.prefixLength += rightNode.prefixLength;
        }

        merged.suffixLength = rightNode.suffixLength;
        if (rightNode.suffixLength == rightNode.segmentLength &&
            leftNode.rightCharacter == rightNode.leftCharacter) {
            merged.suffixLength += leftNode.suffixLength;
        }

        merged.bestLength = max(leftNode.bestLength, rightNode.bestLength);
        if (leftNode.rightCharacter == rightNode.leftCharacter) {
            merged.bestLength = max(
                merged.bestLength,
                leftNode.suffixLength + rightNode.prefixLength
            );
        }

        return merged;
    }

    void build(int nodeIndex, int left, int right) {
        if (left == right) {
            tree[nodeIndex] = {text[left], text[left], 1, 1, 1, 1};
            return;
        }

        int middle = left + (right - left) / 2;
        build(nodeIndex * 2, left, middle);
        build(nodeIndex * 2 + 1, middle + 1, right);

        tree[nodeIndex] = mergeNodes(tree[nodeIndex * 2], tree[nodeIndex * 2 + 1]);
    }

    void update(int nodeIndex, int left, int right, int position, char character) {
        if (left == right) {
            tree[nodeIndex] = {character, character, 1, 1, 1, 1};
            return;
        }

        int middle = left + (right - left) / 2;

        if (position <= middle) {
            update(nodeIndex * 2, left, middle, position, character);
        } else {
            update(nodeIndex * 2 + 1, middle + 1, right, position, character);
        }

        tree[nodeIndex] = mergeNodes(tree[nodeIndex * 2], tree[nodeIndex * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        text = s;
        int length = text.size();

        tree.resize(4 * length);
        build(1, 0, length - 1);

        vector<int> answer;
        answer.reserve(queryIndices.size());

        for (int query = 0; query < queryIndices.size(); ++query) {
            int position = queryIndices[query];
            char character = queryCharacters[query];

            update(1, 0, length - 1, position, character);
            answer.push_back(tree[1].bestLength);
        }

        return answer;
    }
};