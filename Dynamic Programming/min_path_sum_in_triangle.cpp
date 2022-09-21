#include <bits/stdc++.h> 
int f(vector<vector<int>>& triangle,int n, int i,int j,vector<vector<int>> dp){
    if(i==n-1) return triangle[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int down=f(triangle,n,i+1,j,dp)+triangle[i][j];
    int diag=f(triangle,n,i+1,j+1,dp)+triangle[i][j];
    
    return dp[i][j]=min(down,diag);
}

int f2(vector<vector<int>>& triangle, int n,vector<vector<int>> dp){
    for(int i=0;i<n;i++){
        dp[n-1][i]=triangle[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            
            dp[i][j]=min(triangle[i][j]+dp[i+1][j],triangle[i][j]+dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}

int f3(vector<vector<int>>& triangle, int n,vector<vector<int>> dp){
    
    vector<int> front(n,0),cur(n,0);
    for(int i=0;i<n;i++){
        front[i]=triangle[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            
            cur[j]=min(triangle[i][j]+front[j],triangle[i][j]+front[j+1]);
        }
        front=cur;
    }
    return front[0];
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n,-1));
    
//     return f(triangle,n,0,0,dp);
    //return  f2(triangle,n,dp);
    return f3(triangle,n,dp);
}