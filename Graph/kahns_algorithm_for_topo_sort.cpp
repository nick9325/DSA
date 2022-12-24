class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indeg(V);
	    queue<int> q;
	    
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){
	            indeg[x]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	 
	    vector<int> res;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        res.push_back(node);
	        
	        for(auto x:adj[node]){
	            indeg[x]--;
	            if(indeg[x]==0){
	                q.push(x);
	            }
	        }
	    }
	    
	    return res;
	}
};