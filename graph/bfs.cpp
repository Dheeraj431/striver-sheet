class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        vector<bool>used(V,false);
        used[0]=1;
        q.push(0);
        vector<int>path;
        path.push_back(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int u:adj[node]){
                if(!used[u]){
                    q.push(u);
                    used[u]=true;
                    path.push_back(u);
                }
            }
        }
        return path;
    }
};
