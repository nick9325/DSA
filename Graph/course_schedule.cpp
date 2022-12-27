class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> pre) 
    {
        //code here
        vector<int> indeg(N,0);
	    vector<int> adj[N];
	    
	    for(int i=0;i<pre.size();i++){
	        adj[pre[i][1]].push_back(pre[i][0]);
	    }
	    
	    for(int i=0;i<N;i++){
	        for(auto x:adj[i]){
	            indeg[x]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i=0;i<N;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> ord;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ord.push_back(node);
	        
	        for(auto x:adj[node]){
	            indeg[x]--;
	            if(indeg[x]==0){
	                q.push(x);
	            }
	        }
	    }
	    
	    if(ord.size()==N) return ord;
	   
	    return {};
	    
	}
};
