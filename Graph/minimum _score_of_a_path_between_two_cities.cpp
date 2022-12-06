class Solution {
public:

    void dfs(int node,vector<pair<int,int>> g[],int &mn,vector<int> &vis){

        vis[node]=1;
        for(auto it: g[node]){
            mn=min(mn,it.second);
        }
        for(auto it : g[node]){
            if(vis[it.first]==0){
                dfs(it.first,g,mn,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<int> vis(n+1,0);
        vector<pair<int,int>> g[n+1];
        
        
        for(auto x:roads){
            g[x[0]].push_back({x[1],x[2]});
            g[x[1]].push_back({x[0],x[2]});
        }

        int mn= INT_MAX;

 
        dfs(1,g,mn,vis);
        
        
        // vis[0]=1;
        // queue<int> q;
        // q.push(1);
        
        // int mn=INT_MAX;
        
        // while(!q.empty()){
            
        //     int node=q.front();
            
        //     q.pop();
        //     vis[node]=1;
            
        //     for(int i=0; i<g[node].size(); i++){
        //         mn = min(mn, g[node][i].second);
        //         int next = g[node][i].first;
        //         if(vis[next]) continue;
        //         else q.push(next);
        //     }   
        // }
        
        
        return mn;
        
    }
};