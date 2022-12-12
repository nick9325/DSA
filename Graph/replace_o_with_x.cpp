class Solution{
public:
    void bfs(int row,int col,vector<vector<char>> mat, vector<vector<int>> &vis,int dirr[],int dirc[]){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nr=row+dirr[i];
            int nc=col+dirc[i];
            
            if(nr>=0 and nr<mat.size() and nc>=0 and nc<mat[0].size() and !vis[nr][nc] and mat[nr][nc]=='O'){
                bfs(nr,nc,mat,vis,dirr,dirc);
            }
            
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int dirr[]={0,-1,0,1};
        int dirc[]={1,0,-1,0};
        for(int j=0;j<m;j++){
            
             if(!vis[0][j] and mat[0][j]=='O' ){
                        bfs(0,j,mat,vis,dirr,dirc);
              }
              if(!vis[n-1][j] and mat[n-1][j]=='O'){
                        bfs(n-1,j,mat,vis,dirr,dirc);
              }
            
        }
         for(int i=0;i<n;i++){
            
             if(!vis[i][0] and mat[i][0]=='O' ){
                    bfs(i,0,mat,vis,dirr,dirc);
              }
              if(!vis[i][m-1] and mat[i][m-1]=='O'){
                    bfs(i,m-1,mat,vis,dirr,dirc);
              }
            
        }
        
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(!vis[i][j] and mat[i][j]=='O'){
                        mat[i][j]='X';
                    }
                }
            }
        
        
        return mat;
        
        
    }
};