class Solution {
    
  private:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid,int n,int m){
        
        queue<pair<int,int>> q;
        vis[row][col]=1;
        q.push({row,col});
        
        while(!q.empty()){
            
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=r+i;
                    int ncol=c+j;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                    
                }
            }
        }
        
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,vis,grid,n,m);
                }
            }
        }
        return ans;
    }
};