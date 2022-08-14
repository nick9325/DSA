int solveMem(vector<int> &num , int x , vector<int>&dp)
{
//     Base Case
    if(x == 0) 
        return 0;
    if(x < 0) 
        return INT_MAX;
    
//     dp case 
    if(dp[x] != -1) 
        return dp[x];
//     Recursive case
    
    int mini = INT_MAX;
    
    for(int i = 0; i < num.size(); ++i)
    {
        int ans = solveMem(num , x-num[i] , dp);
        if(ans != INT_MAX)
        mini = min(mini , ans+1);
        
    }
//     Recrence Reletion
    dp[x] = mini;
    
    return mini;
}
//tabulation
int solveTab(vector<int> &num,int x,vector<int> dp){
    dp[0]=0;
    
    for(int i=1;i<=x;i++){
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0 and dp[i-num[j]]!=INT_MAX)
                dp[i]=min(dp[i],1+dp[i-num[j]]);
         }
    }
    return dp[x];
}

//

int minimumElements(vector<int> &num, int x)
{
    vector<int>dp(x+1,-1);
    vector<int>dp1(x+1 , INT_MAX);
    
    
//     int ans = solveMem(num , x , dp);
    int ans=solveTab(num,x,dp1);
    if(ans == INT_MAX) 
        return -1;
    else
        return ans;
   
}