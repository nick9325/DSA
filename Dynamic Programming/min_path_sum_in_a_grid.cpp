
int solveMem(int i,int j,vector<vector<int>> &dp,vector<vector<int>>&grid){
    
    if(i==0 and j==0) return grid[i][j];
    
    if(i<0 or j<0) return 1e9;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int up=solveMem(i-1,j,dp,grid)+grid[i][j];
    int left=solveMem(i,j-1,dp,grid)+grid[i][j];
    
    return dp[i][j]=min(up,left);
}

int solveTab(int m,int n,vector<vector<int>> &grid){
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            if(i==0 and j==0){ 
                dp[i][j]=grid[i][j];
            }
            else{
                int up=grid[i][j],left=grid[i][j];
                if(i>0) up+=dp[i-1][j];
                else up+=1e9;
                if(j>0) left+=dp[i][j-1];
                else left+=1e9;
                
                dp[i][j]=min(up,left);
                
            }
            
        }
    }
    return dp[m-1][n-1];
}
int solveSO(int m,int n,vector<vector<int>> &grid){
    vector<int> dp(n,0);
    for(int i=0;i<m;i++){
        vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            
            if(i==0 and j==0){ 
                temp[j]=grid[i][j];
            }
            else{
                int up=grid[i][j],left=grid[i][j];
                if(i>0) up+=dp[j];
                else up+=1e9;
                if(j>0) left+=temp[j-1];
                else left+=1e9;
                
                temp[j]=min(up,left);
                
            }
            
        }
        dp=temp;
    }
    return dp[n-1];
}

int minSumPath(vector<vector<int>> &grid) {
   int m=grid.size(),n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
//     return solveMem(m-1,n-1,dp,grid);
//     return solveTab(m,n,grid);
    
    return solveSO(m,n,grid);
    
}