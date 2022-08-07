#include<bits/stdc++.h>
using namespace std;

//memoization >top down >o(n),o(n)
int solve(int n,vector<int> &dp){
    if(n<=1) return n;
    
    if(dp[n]!=-1) return dp[n];
    
    dp[n]=solve(n-1,dp)+solve(n-2,dp);
    
    return dp[n];
    
}

//tabulation >bottum up >o(n),o(n)
int solve2(int n,vector<int> dp){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//tabulation >bottum up >o(n),o(1)
int solve3(int n){
    int c=0;
    int p1=0;
    int p2=1;
    
    for(int i=2;i<=n;i++){
        c=p1+p2;
        p1=p2;
        p2=c;
    }
    
    return p2;
    
}
int main()
{
    int n; cin>>n;
    vector<int> dp(n+1);
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
   
//    cout<<solve(n,dp)<<endl;
//     cout<<solve2(n,dp)<<endl;
    cout<<solve3(n)<<endl;
}