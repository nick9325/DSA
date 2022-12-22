class Solution {

private:
    bool dfs(int s,vector<int> &col,vector<vector<int>> adj,int c){
        col[s]=c;

        for(auto x:adj[s]){
            if(col[x]==-1){
                if(!dfs(x,col,adj,1-c)) return false;
            }
            else if(col[x]==col[s]) return false;
        }
        return true;
    }
    bool bfs(int s,vector<int> &col,vector<vector<int>> adj){
        
        col[s]=0;

        queue<int> q;
        q.push(s);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto x:adj[node]){
                if(col[x]==-1){
                    col[x]=!col[node];
                    q.push(x);
                }
                else if(col[x]==col[node]) return false;
            }
        }
        return true;

    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {

        vector<vector<int>> adj(n+1);

        for(int i=0;i<d.size();i++){
            adj[d[i][0]].push_back(d[i][1]);
            adj[d[i][1]].push_back(d[i][0]);
        }

        vector<int> col(n+1,-1);

        for(int i=0;i<=n;i++){
            if(col[i]==-1){
                // if(!dfs(i,col,adj,0)) return false;
                if(!bfs(i,col,adj)) return false;
            }
        }

        return true;
        

    }
};