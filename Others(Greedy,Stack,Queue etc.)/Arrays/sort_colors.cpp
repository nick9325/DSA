class Solution {
public:
    void sortColors(vector<int>& nums) {


        //Approach 1 T=O(2N) S=O(1)
        
        int cnt0=0,cnt1=0,cnt2=0;

        for(auto x:nums){
            if(x==0) cnt0++;
            else if(x==1) cnt1++;
            else cnt2++;
        }

        for(int i=0;i<cnt0;i++){
            nums[i]=0;
        }
        for(int i=cnt0;i<cnt1+cnt0;i++){
            nums[i]=1;
        }
        for(int i=cnt0+cnt1;i<cnt0+cnt1+cnt2;i++){
            nums[i]=2;
        }
        

        //Approach 2 T=O(n) S=O(1)

        int i=0,j=nums.size()-1,cur=0;
        
        while(cur<=j){
            
            if(nums[cur]==0){
                swap(nums[cur++],nums[i++]);
            }
            else if(nums[cur]==2){
                swap(nums[cur],nums[j--]);
            }
            else{
                cur++;
            }

        }
        
    }
};