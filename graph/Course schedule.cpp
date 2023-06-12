//Problem Link : https://practice.geeksforgeeks.org/problems/course-schedule/1
vector<int> findOrder(int n, int m, vector<vector<int>> p) {
    vector<int> adj[n];
    vector<int> indeg(n, 0); // Initialize indeg vector with zeros

    for (int i = 0; i < m; i++) {
        adj[p[i][1]].push_back(p[i][0]);
        indeg[p[i][0]]++; // Update indeg for prerequisites
    }

    queue<int> q;
    for (int node = 0; node < n; node++) {
        if (indeg[node] == 0) {
            q.push(node);
        }
    }

    vector<int> seq;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        seq.push_back(x);
        for (auto u : adj[x]) {
            indeg[u]--;
            if (indeg[u] == 0) {
                q.push(u);
            }
        }
    }

    if (seq.size() != n) {
        // There is a cycle in the graph, it's not possible to finish all tasks
        return {};
    }

    return seq;
}
