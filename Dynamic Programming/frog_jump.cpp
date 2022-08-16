#include<bits/stdc++.h>
int solveMem(int n,vector<int> &heights,vector<int> &dp){
    
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int left=solveMem(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    int right=INT_MAX;
    if(n>1){
        right=solveMem(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
    }
    return dp[n]=min(left,right);
}

int solveTab(int n,vector<int> &heights,vector<int> dp){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int l=dp[i-1]+abs(heights[i]-heights[i-1]);
        int r=INT_MAX;
        if(i>1)
            r=dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(l,r);
    }
      return dp[n-1];
}
int solveSO(int n,vector<int> &heights,vector<int> dp){
    int pre=0;
    int pre2=0;
    for(int i=1;i<n;i++){
        int l=pre+abs(heights[i]-heights[i-1]);
        int r=INT_MAX;
        if(i>1)
            r=pre2+abs(heights[i]-heights[i-2]);
        int cur=min(l,r);
        pre2=pre;
        pre=cur;
    }
      return pre;
}

int frogJump(int n, vector<int> &heights)
{
//     vector<int> dp(n+1,-1);
    vector<int> dp1(n,-1);
    
//     return solveMem(n-1,heights,dp);
//     return solveTab(n,heights,dp1);
    return solveSO(n,heights,dp1);
}