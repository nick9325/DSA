class Solution {
public:

    int binarySearch(vector<int> nums,int s,int e){

        while(s<=e){
            int mid=(s+e)/2;

            if(nums[mid]-nums[0]>=mid){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return nums[e];

    }
    int findDuplicate(vector<int>& nums) {

        //Approach 1

        sort(nums.begin(),nums.end());

        if(nums.size()>=2 and nums[0]==nums[1]) return nums[0]; 

        return binarySearch(nums,0,nums.size()-1);


        //Approach 2 T=O(n) S=O(1)

        int n=nums.size();

        for(int x:nums){
            int mark=abs(x);
            if(nums[mark]<0) return mark;
            nums[mark]=-nums[mark];
        }

        return n;


        //Approach 3 T=O(n) S=O(1)

        int slow=nums[0],fast=nums[0];

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;
    }
};