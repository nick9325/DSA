#include <bits/stdc++.h> 

int solveMem(int m,int n,vector<vector<int>> &dp){
    
    if(m==0 and n==0) return 1;
    if(m<0 or n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    int left=solveMem(m,n-1,dp);
    int up=solveMem(m-1,n,dp);
    
    return dp[m][n]=left+up;
}
int solveTab(int m, int n){
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            if(i==0 and j==0){
                dp[i][j]=1;
                continue;
            }
            int left=0,up=0;
            
            if(j>0) left=dp[i][j-1];
            if(i>0) up=dp[i-1][j];
            
            dp[i][j]=left+up;
        }
    }
    
    return dp[m-1][n-1];
    
}

int solveSO(int m,int n){
    
    vector<int> cur(n,0);
    
    for(int i=0;i<m;i++){
          vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            
            if(i==0 and j==0){
                temp[j]=1;
                continue;
            }
            
            int left=0,up=0;
            if(i>0) up=cur[j];
            if(j>0) left=temp[j-1];
            
            temp[j]=up+left;
        }
        cur=temp;
    }
    
    return cur[n-1];
    
}

int uniquePaths(int m, int n) {
    
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
//     return solveMem(m-1,n-1,dp);
    
//     return solveTab(m,n);
    
    return solveSO(m,n);
    
}