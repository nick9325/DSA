class Solution 
  private:
    void dfs(int node,vector<int> adj[],vector<int> &vis){
        vis[node]=1;
        
        for(auto x:adj[node]){
            if(!vis[x]){
                vis[x]=1;
                dfs(x,adj,vis);
            }
        }
        
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<int> vis(V+1,0);
        vector<int> adjL[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 and i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adjL,vis);
                ans++;
            }
        }
        
        return ans;
        
    }