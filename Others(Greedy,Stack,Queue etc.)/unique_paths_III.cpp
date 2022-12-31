class Solution {
public:

    void solve(int i,int j,vector<vector<int>> grid,int k,int &ans,int empty){

        if(i>=grid.size() or i<0 or j>=grid[0].size() or j<0 or grid[i][j]==-1) return;

        if(k==empty and grid[i][j]==2){
            ans++;
            return;
        }
        grid[i][j]=-1;
        solve(i-1,j,grid,k+1,ans,empty);
        solve(i,j+1,grid,k+1,ans,empty);
        solve(i+1,j,grid,k+1,ans,empty);
        solve(i,j-1,grid,k+1,ans,empty);
        grid[i][j]=0;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int empty=0;
        int sx=0,sy=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    empty++;
                }
                else if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }
        }

        // int empty=grid.size()*grid[0].size()-cnt-2;
        int ans=0;
        solve(sx,sy,grid,0,ans,empty+1);

        return ans;
    }
};