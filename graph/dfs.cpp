class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
   //WITH LIST
    void dfs(int node, vector<int>&visited, vector<int>&seq,vector<int>adj[]){
        if(visited[node])
            return;
        visited[node]=1;
        seq.push_back(node);
        for(auto u:adj[node]){
            dfs(u,visited,seq,adj);
        }
    }
  //WITH GRID
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[node] = true;
    for (int i = 0; i < adj.size(); i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, visited, adj);
        }
    }
}
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V);
        vector<int>seq;
        dfs(0,visited,seq,adj);
        return seq;
    }
};
