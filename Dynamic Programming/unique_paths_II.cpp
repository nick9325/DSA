
int mod=(int)(1e9+7);


int solveMem(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &mat){
    
    if(i>=0 and j>=0 and mat[i][j]==-1) return 0;
    if(i==0 and j==0) return 1;
    if(i<0 or j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up=solveMem(i-1,j,dp,mat);
    int left=solveMem(i,j-1,dp,mat);
    
    return dp[i][j]=(up+left)%mod;
}


int solveTab(vector<vector<int>> &mat,int n,int m){
     vector<vector<int>> dp(n,vector<int>(m,-1));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(mat[i][j]==-1){
                dp[i][j]=0;
            }
            else if(i==0 and j==0){
                dp[i][j]=1;
            }
            else{
                int up=0,left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=(up+left)%mod;
            }
            
        }
    }
    
    return dp[n-1][m-1];
}


int solveSO(vector<vector<int>> &mat,int n,int m){
    
    vector<int> dp(m,0);
    
    for(int i=0;i<n;i++){
        vector<int> temp(m,0);
        for(int j=0;j<m;j++){
            
            if(mat[i][j]==-1){
                temp[j]=0;
            }
            else if(i==0 and j==0){
                temp[j]=1;
            }
            else{
                int up=0,left=0;
                if(i>0) up=dp[j];
                if(j>0) left=temp[j-1];
                
                temp[j]=(up+left)%mod;
            }
            
        }
        dp=temp;
    }
    
    return dp[m-1];    
}


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {

    vector<vector<int>> dp(n,vector<int>(m,-1));
    
//     return solveMem(n-1,m-1,dp,mat);
    
//     return solveTab(mat,n,m);
    return solveSO(mat,n,m);
}