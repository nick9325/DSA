class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp(1001,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        dp[4]=11;
        dp[5]=24;

        if(n<=5) return dp[n];

        long long int mod=1e9+7;

        for(int i=6;i<=n;i++){
            dp[i]=(2*dp[i-1]+dp[i-3])%mod;
        }

        return dp[n];
    }
};