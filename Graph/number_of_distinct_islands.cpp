class Solution {
    
  private:
  void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &vis,vector<pair<int,int>> &p,int r0,int c0){
      vis[row][col]=1;
      p.push_back({row-r0,col-c0});
      
      int dr[]={-1,0,1,0};
      int dc[]={0,-1,0,1};
      
      for(int i=0;i<4;i++){
          
          int r=row+dr[i];
          int c=col+dc[i];
          
          if(r>=0 and r<grid.size() and c>=0 and c<grid[0].size() and grid[r][c]==1 and !vis[r][c]){
              dfs(r,c,grid,vis,p,r0,c0);
          }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>> s;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    vector<pair<int,int>> p;
                    dfs(i,j,grid,vis,p,i,j);
                    s.insert(p);
                }
            }
        }
        
        return s.size();
        
    }
};
