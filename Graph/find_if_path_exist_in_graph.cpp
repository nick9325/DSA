class Solution {
private:
    bool dfs(int s,vector<vector<int>> res,vector<bool> &vis,int dest){
        vis[s]=true;

        for(auto x:res[s]){
            if(!vis[x]){
                if(x==dest) return true;
                if(dfs(x,res,vis,dest)) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<bool> vis(n,0);
        vector<vector<int>> res(n);
        for(auto x:edges){
            res[x[0]].push_back(x[1]);
            res[x[1]].push_back(x[0]);
        }
        
        // return dfs(source,res,vis,destination);

        queue<int> q;

        q.push(source);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto x:res[node]){
                if(x==destination) return true;
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
            }
        }

        return false;
      
        
    }
};