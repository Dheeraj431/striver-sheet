// Problem Link : https://practice.geeksforgeeks.org/problems/number-of-provinces/1
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<bool>&visited,vector<int>adj[]){
        if(visited[node])
            return;
        visited[node]=1;
        for(auto x : adj[node]){
            dfs(x,visited,adj);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool>visited(V,0);
        int ans=0;
        vector<int>adjlist[V];
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[i].size(); j++){
                if(i!=j && adj[i][j]){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        for(int node=0; node<V; node++){
            if(!visited[node]){
                dfs(node,visited,adjlist);
                ans++;
            }
        }
        return ans;
    }
};
