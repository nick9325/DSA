int solveMem(vector<int> &nums,int n,vector<int> &dp){
    if(n==0) return nums[n];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int pick=nums[n]+solveMem(nums,n-2,dp);
    
    int nonpick=solveMem(nums,n-1,dp);
    
    return dp[n]=max(pick,nonpick);
}
int solveTab(vector<int> &nums,vector<int> &dp){
    dp[0]=nums[0];
    
    for(int i=1;i<nums.size();i++){
        
        int pick=nums[i];
        if(i>1) pick+=dp[i-2];
        int nonpick=dp[i-1];
        
        dp[i]=max(pick,nonpick);
    }
    
    return dp[nums.size()-1];   
}

int solveSO(vector<int> &nums){
    int prev=nums[0];
    int prev2=0;
    
    for(int i=1;i<nums.size();i++){
        int pick=nums[i];
        if(i>1)
            pick+=prev2;
        int nonpick=prev;
        int cur=max(pick,nonpick);        
        prev2=prev;
        prev=cur; 
    }
    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size()+1,-1);
     vector<int> dp1(nums.size(),-1);
//     return solveMem(nums,nums.size()-1,dp);
//     return solveTab(nums,dp1);
    return solveSO(nums);
}