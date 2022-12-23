class Solution {
private:
    int profit(int i,int buy,vector<int> prices,int n,vector<vector<int>> &dp){
        if(i>=n) return 0;
        int prof=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            prof=max(-prices[i]+profit(i+1,0,prices,n,dp),profit(i+1,1,prices,n,dp));
        }
        else{
            prof=max(prices[i]+profit(i+2,1,prices,n,dp),profit(i+1,0,prices,n,dp));
        }
        return dp[i][buy]=prof;
    }
    int solve()
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return profit(0,1,prices,prices.size(),dp);
    }
};