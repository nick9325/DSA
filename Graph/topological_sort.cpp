class Solution
{
    private:
        void dfs(int s,vector<int> adj[],vector<int> &vis,stack<int> &st){
            vis[s]=1;
            
            for(auto x:adj[s]){
                if(!vis[x]){
                    dfs(x,adj,vis,st);
                }
            }
            st.push(s);
        }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    stack<int> st;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    vector<int> res;
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    
	    return res;
	}
};