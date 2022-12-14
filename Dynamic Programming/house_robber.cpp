class Solution {
public:

    int solve(vector<int> nums,int i,vector<int> &dp){
        if(i<0) return 0;
        if(i==0) return nums[i];
        if(dp[i]!=-1) return dp[i];

        int move1=solve(nums,i-1,dp);
        int move2=nums[i]+solve(nums,i-2,dp);


        return dp[i] = max(move1,move2);
    }

    int solvetab(vector<int> nums,vector<int> &dp){

        dp[0]=nums[0];

        for(int i=1;i<nums.size();i++){

            int move1=dp[i-1];

            int move2=nums[i];
            if(i-2>=0) move2+=dp[i-2];

            dp[i]=max(move1,move2);

        }

        return dp[nums.size()-1];

    }

    int rob(vector<int>& nums) {
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),-1);
        // return solve(nums,nums.size()-1,dp);
        return solvetab(nums,dp);

    }
};