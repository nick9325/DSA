class Solution {
  private:
    bool dfs(int s,vector<int> adj[],vector<int> &vis,vector<int> &pv,vector<int> &check){
        vis[s]=1;
        check[s]=0;
        pv[s]=1;
        
        for(auto x:adj[s]){
            if(!vis[x]){
                if(dfs(x,adj,vis,pv,check)){ 
                    check[x]=0;
                    return true;
                }
            }
            else if(pv[x]){
                check[x]=0;
                return true;
            }
        }
        check[s]=1;
        pv[s]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> check(V,0);
        vector<int> res;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathVis,check);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i]==1){
                res.push_back(i);
            }
        }
        
        return res;
    }
};
