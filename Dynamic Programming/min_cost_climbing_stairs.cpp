class Solution {
public:
    
    //memoization
    int solve(vector<int> cost,int n,vector<int> &dp){
        

        if(n==0) return cost[0];
        
        if(n==1) return cost[1];
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=min(solve(cost,n-1,dp),solve(cost,n-2,dp))+cost[n];
        
    }
    //tabulation
    int solve2(vector<int> cost,int n,vector<int> &dp){
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        
        return min(dp[n-1],dp[n-2]);
        
    }
    //space optimization
    int solve3(vector<int> cost,int n){
        int p=cost[0];
        int p2=cost[1];
        
        for(int i=2;i<n;i++){
            int cur=min(p2,p)+cost[i];
            p=p2;
            p2=cur;
        }
        
        return min(p2,p);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);  
        // return min(solve(cost,n-1,dp),solve(cost,n-2,dp));
         // return solve2(cost,n,dp);
        
        return solve3(cost,n);
    }
};