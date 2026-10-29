class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adjacency.assign(n, {});
        for (const auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        subtreeSize.assign(n, 1);
        heavyChild.assign(n, -1);
        chainHead.assign(n, 0);
        tin.assign(n, 0);

        computeHeavyChildren(0, -1);
        timer = 0;
        decompose(0, 0);

        nodeMask.resize(n);
        positionMask.assign(n, 0);

        for (int node = 0; node < n; node++) {
            nodeMask[node] = 1 << (s[node] - 'a');
            positionMask[tin[node]] = nodeMask[node];
        }

        segmentTree.assign(4 * n, 0);
        buildSegmentTree(1, 0, n - 1);

        vector<bool> answer;
        answer.reserve(queries.size());

        for (const string& rawQuery : queries) {
            istringstream stream(rawQuery);
            string operation;
            stream >> operation;

            if (operation == "update") {
                int node;
                char character;
                stream >> node >> character;

                nodeMask[node] = 1 << (character - 'a');
                positionMask[tin[node]] = nodeMask[node];

                updateSegmentTree(1, 0, n - 1, tin[node], nodeMask[node]);
            } else {
                int left, right;
                stream >> left >> right;

                int pathMask = queryPath(left, right);
                answer.push_back(__builtin_popcount(pathMask) <= 1);
            }
        }

        return answer;
    }

private:
    vector<vector<int>> adjacency;
    vector<int> parent, depth, subtreeSize, heavyChild, chainHead, tin, nodeMask, positionMask, segmentTree;
    int timer;

    void computeHeavyChildren(int node, int previous) {
        parent[node] = previous;
        int largestChild = -1;
        int largestSize = 0;

        for (int child : adjacency[node]) {
            if (child == previous) continue;

            depth[child] = depth[node] + 1;
            computeHeavyChildren(child, node);
            subtreeSize[node] += subtreeSize[child];

            if (subtreeSize[child] > largestSize) {
                largestSize = subtreeSize[child];
                largestChild = child;
            }
        }

        heavyChild[node] = largestChild;
    }

    void decompose(int node, int head) {
        chainHead[node] = head;
        tin[node] = timer++;

        if (heavyChild[node] != -1) {
            decompose(heavyChild[node], head);
        }

        for (int child : adjacency[node]) {
            if (child == parent[node] || child == heavyChild[node]) continue;
            decompose(child, child);
        }
    }

    void buildSegmentTree(int index, int left, int right) {
        if (left == right) {
            segmentTree[index] = positionMask[left];
            return;
        }

        int middle = (left + right) / 2;
        buildSegmentTree(2 * index, left, middle);
        buildSegmentTree(2 * index + 1, middle + 1, right);
        segmentTree[index] = segmentTree[2 * index] ^ segmentTree[2 * index + 1];
    }

    void updateSegmentTree(int index, int left, int right, int position, int value) {
        if (left == right) {
            segmentTree[index] = value;
            return;
        }

        int middle = (left + right) / 2;
        if (position <= middle) {
            updateSegmentTree(2 * index, left, middle, position, value);
        } else {
            updateSegmentTree(2 * index + 1, middle + 1, right, position, value);
        }

        segmentTree[index] = segmentTree[2 * index] ^ segmentTree[2 * index + 1];
    }

    int querySegmentTree(int index, int left, int right, int queryLeft, int queryRight) {
        if (queryRight < left || right < queryLeft) return 0;
        if (queryLeft <= left && right <= queryRight) return segmentTree[index];

        int middle = (left + right) / 2;
        return querySegmentTree(2 * index, left, middle, queryLeft, queryRight) ^
               querySegmentTree(2 * index + 1, middle + 1, right, queryLeft, queryRight);
    }

    int queryPath(int u, int v) {
        int pathMask = 0;

        while (chainHead[u] != chainHead[v]) {
            if (depth[chainHead[u]] < depth[chainHead[v]]) swap(u, v);

            pathMask ^= querySegmentTree(
                1, 0, (int)tin.size() - 1,
                tin[chainHead[u]], tin[u]
            );

            u = parent[chainHead[u]];
        }

        if (depth[u] > depth[v]) swap(u, v);

        pathMask ^= querySegmentTree(
            1, 0, (int)tin.size() - 1,
            tin[u], tin[v]
        );

        return pathMask;
    }
};