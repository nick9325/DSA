class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indeg(V,0);
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
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto x:adj[node]){
                indeg[x]--;
                if(indeg[x]==0){
                    q.push(x);
                }
            }
        }
        
        if(cnt==V) return false;
        return true;
    }
};