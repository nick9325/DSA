class Solution {
public:
    int solve(string t,string s,int i,int j,vector<vector<int>> &dp){

        if(i==t.size() || j==s.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(t[i]==s[j]) return dp[i][j]=1+solve(t,s,i+1,j+1,dp);

        else return dp[i][j]=max(solve(t,s,i+1,j,dp),solve(t,s,i,j+1,dp));

    }

    int solvetab(string t,string s){
        vector<vector<int>> dp(t.size()+1,vector<int>(s.size()+1,0));
        
        for(int i=t.size()-1;i>=0;i--){
            for(int j=s.size()-1;j>=0;j--){
                if(t[i]==s[j]) dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        
        return dp[0][0];

    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        // return solve(text1,text2,0,0,dp);
        return solvetab(text1,text2);
    }
};