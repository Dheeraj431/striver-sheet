//Problem Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectcycle(int node, int parent, vector<int>& vis, vector<int> adj[]) {
    vis[node] = 1;

    for (auto next : adj[node]) {
        if (!vis[next]) {
            if (detectcycle(next, node, vis, adj))
                return true;
        } else if (next != parent) {
            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0); // Initialize the visited array

    for (int i = 0; i < V; i++) {
        if (!vis[i]) { // Check if the current node is not visited
            if (detectcycle(i, -1, vis, adj)) // Call detectcycle for the current node
                return true;
        }
    }

    return false; // No cycle found in any node
}


};
