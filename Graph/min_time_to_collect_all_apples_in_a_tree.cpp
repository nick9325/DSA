class Solution {
public:
    int solve(int s,vector<vector<int>> &adj,vector<int> &vis,vector<bool> hA){

        int totTime=0;
        vis[s]=true;
        for(auto x:adj[s]){
            if(!vis[x]){
                totTime+=solve(x,adj,vis,hA);
            }
        }


        if(s==0) return totTime;

        if(hA[s] || totTime>0){
            totTime+=2;
        }

        return totTime;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> adj(n);

        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);  
            adj[x[1]].push_back(x[0]);
        }

        vector<int> vis(n,0);

        return solve(0,adj,vis,hasApple);

    }
};