class Solution {
  public:
  
    int numberOfEnclaves(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        
        
        int dirr[]={0,-1,0,1};
        int dirc[]={1,0,-1,0};
        
        for(int j=0;j<m;j++){
            
             if(!vis[0][j] and mat[0][j]==1 ){
                        q.push({0,j});
              }
              if(!vis[n-1][j] and mat[n-1][j]==1){
                        q.push({n-1,j});
              }
            
        }
         for(int i=0;i<n;i++){
            
             if(!vis[i][0] and mat[i][0]==1 ){
                    q.push({i,0});
              }
              if(!vis[i][m-1] and mat[i][m-1]==1){
                    q.push({i,m-1});
              }
            
        }
        
        while(!q.empty()){
            
            int row=q.front().first;
            int col=q.front().second;
            
            q.pop();
            
            vis[row][col]=1;
            for(int i=0;i<4;i++){
                int nr=row+dirr[i];
                int nc=col+dirc[i];
                
                if(nr>=0 and nr<mat.size() and nc>=0 and nc<mat[0].size() and !vis[nr][nc] and mat[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
                
            }
                    
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(!vis[i][j] and mat[i][j]==1){
                        cnt++;
                    }
                }
            }
        
        return cnt;
        
    }
};