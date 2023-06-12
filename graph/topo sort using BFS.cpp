//Problem Link : https://practice.geeksforgeeks.org/problems/topological-sort/1
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indeg(V);
	    for(int node=0; node<V; node++){
	        for(auto u:adj[node]){
	            indeg[u]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0; i<V; i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int>topo; 
	    while(!q.empty()){
	        int x=q.front();
	        q.pop();
	        topo.push_back(x);
	        for(auto u:adj[x]){
	            indeg[u]--;
	            if(indeg[u]==0){
	                q.push(u);
	            }
	        }
	    }
	    /*
	    	cycle check 
		if(topo.size()==V)->no cycle
		else  there is a cycle in the directed.graph()	
	    */
	    return topo;
	}
