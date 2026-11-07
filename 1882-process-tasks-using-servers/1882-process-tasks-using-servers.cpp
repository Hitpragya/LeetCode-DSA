class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int serverCount = servers.size();
        int taskCount = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> freeServers;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyServers;

        for (int index = 0; index < serverCount; ++index) {
            freeServers.push({servers[index], index});
        }

        vector<int> assignedServer(taskCount);
        long long currentTime = 0;

        for (int taskIndex = 0; taskIndex < taskCount; ++taskIndex) {
            currentTime = max(currentTime, (long long)taskIndex);

            while (!busyServers.empty() && busyServers.top().first <= currentTime) {
                int serverIndex = busyServers.top().second;
                busyServers.pop();
                freeServers.push({servers[serverIndex], serverIndex});
            }

            if (freeServers.empty()) {
                currentTime = busyServers.top().first;

                while (!busyServers.empty() && busyServers.top().first == currentTime) {
                    int serverIndex = busyServers.top().second;
                    busyServers.pop();
                    freeServers.push({servers[serverIndex], serverIndex});
                }
            }

            auto [serverWeight, serverIndex] = freeServers.top();
            freeServers.pop();

            assignedServer[taskIndex] = serverIndex;
            busyServers.push({currentTime + tasks[taskIndex], serverIndex});
        }

        return assignedServer;
    }
};