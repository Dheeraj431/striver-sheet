class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int>&visited, vector<int>&seq,vector<int>adj[]){
        if(visited[node])
            return;
        visited[node]=1;
        seq.push_back(node);
        for(auto u:adj[node]){
            dfs(u,visited,seq,adj);
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
