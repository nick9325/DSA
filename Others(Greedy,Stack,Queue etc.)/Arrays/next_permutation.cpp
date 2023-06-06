class Solution {
public:
    void permutations(vector<int> nums,int index,vector<vector<int>> &perms){
        if(index==nums.size()){
            perms.push_back(nums);
            for(int i=0;i<nums.size();i++){
                cout<<nums[i];
            }
            cout<<" ";
            return;
        }


        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            permutations(nums,index+1,perms);
            swap(nums[index],nums[i]);
        }

    }

    void nextPermutation(vector<int>& nums) {
        
       // Brute force --> T=O(N!xN),S-O(1);

        vector<vector<int>> perms;
        vector<int> arr=nums;

        sort(arr.begin(),arr.end());

        permutations(arr,0,perms); 


        for(int i=0;i<perms.size();i++){
            if(perms[i]==nums){
                nums=perms[(i+1)%perms.size()];
                return;
            }
        }


       // Approach 2 

        next_permutation(nums.begin(),nums.end());


       // Approach 3  T=O(nlogn) S=O(1)

        int i=nums.size()-1;
        int idx=0;

        while(i>0){

            if(nums[i]>nums[i-1]){
                
                sort(nums.begin()+i,nums.end());

                for(int j=i;j<nums.size();j++){
                    if(nums[i-1]<nums[j]){    
                      swap(nums[i-1],nums[j]);
                      break;
                    }
                }

                sort(nums.begin()+i,nums.end());
                break;
            }
            i--;

        }

        if(i==0){
            sort(nums.begin(),nums.end());
        }


       // Just better version of approach 3 T= O(3N) , S= O(1)

        int i=nums.size()-1;
        int idx=-1;
        for(;i>0;i--){
            if(nums[i]>nums[i-1]){
                idx=i;
                break;
            }
        }

        if(idx==-1){
            reverse(nums.begin(),nums.end());
        }
        else{

            for(int j=nums.size()-1;j>=i;j--){
                if(nums[idx-1]<nums[j]){
                    swap(nums[idx-1],nums[j]);
                    break;
                }
            }

            reverse(nums.begin()+idx,nums.end());
            

        }


    }
};