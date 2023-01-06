class Solution {
public:
    int solve(vector<int>& costs,vector<int> &dp,int coins,int i){
        if(coins<=0) return 0;
        
        if(i==costs.size()-1){
            if(costs[i]<=coins) return 1;
            else return 0;
        } 
     
        if(dp[i]!=-1) return dp[i];
        int take=0;
        if(coins>=costs[i]){
            take=1+solve(costs,dp,coins-costs[i],i+1);
        }
        int ntake=solve(costs,dp,coins,i+1);

        return dp[i]=max(take,ntake);

    }
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(),costs.end());


        vector<int> dp(costs.size(),-1);

        return solve(costs,dp,coins,0);

    }
};