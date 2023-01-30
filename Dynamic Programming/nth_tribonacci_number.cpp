class Solution {
public:

    int tribonaccis(int n,vector<int> &dp) {
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=tribonaccis(n-1,dp)+tribonaccis(n-2,dp)+tribonaccis(n-3,dp);
    }

    int tribo(int n,vector<int> dp){

        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }   
        return dp[n];
    }
    int trib(int n){
        
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        int fs=0;
        int ss=1;
        int ts=1;
        int next=0;
        for(int i=3;i<=n;i++){
            next=fs+ss+ts;
            fs=ss;
            ss=ts;
            ts=next;

        }   
        return next;

    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);

        // return tribonaccis(n,dp);

        // return tribo(n,dp);
        return trib(n);
    }
};