class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (const auto& invocation : invocations) {
            graph[invocation[0]].push_back(invocation[1]);
        }

        vector<bool> suspicious(n, false);
        queue<int> pendingMethods;

        suspicious[k] = true;
        pendingMethods.push(k);

        while (!pendingMethods.empty()) {
            int currentMethod = pendingMethods.front();
            pendingMethods.pop();

            for (int calledMethod : graph[currentMethod]) {
                if (!suspicious[calledMethod]) {
                    suspicious[calledMethod] = true;
                    pendingMethods.push(calledMethod);
                }
            }
        }

        for (const auto& invocation : invocations) {
            int caller = invocation[0];
            int callee = invocation[1];

            if (!suspicious[caller] && suspicious[callee]) {
                vector<int> allMethods(n);
                iota(allMethods.begin(), allMethods.end(), 0);
                return allMethods;
            }
        }

        vector<int> remainingMethods;

        for (int method = 0; method < n; ++method) {
            if (!suspicious[method]) {
                remainingMethods.push_back(method);
            }
        }

        return remainingMethods;
    }
};