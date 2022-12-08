class Solution 
{  
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int dr[]={0,-1,0,1};
        int dc[]={1,0,-1,0};
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                
            }
        }
        
        int mx=0;
        while(!q.empty()){
            
            int r=q.front().first.first;
            int c=q.front().first.second;
            int ans=q.front().second;
            mx=max(mx,ans);
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 and nr<grid.size() and nc>=0 and nc<grid[0].size() and grid[nr][nc]==1 and vis[nr][nc]==0){
                    vis[nr][nc]=2;
                    q.push({{nr,nc},ans+1});
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]!=2 and grid[i][j]==1) return -1;
            }
        }
            
        return mx;
            
            
    }
};