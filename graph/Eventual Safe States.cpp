//Problem Link : https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>revAdj[V];
        for(int i=0; i<V; i++){
            for(auto it:adj[i]){
                revAdj[it].push_back(i);
            }
        }
        
        vector<int>indeg(V);
        for(int i=0; i<V; i++){
            for(auto it : revAdj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int node=0; node<V; node++){
            if(!indeg[node]){
                q.push(node);
            }
        }
        vector<int>safeNodes;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            safeNodes.push_back(x);
            for(auto it:revAdj[x]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};
