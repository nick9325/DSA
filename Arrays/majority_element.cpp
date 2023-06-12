class Solution {
public:
    int majorityElement(vector<int>& nums) {
    
        
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++) {
            m[nums[i]]++;
            
            if(m[nums[i]]>(nums.size())/2) return nums[i];
        }

        return -1;

        //algorithm


        int cnt=0,ele=-1;

        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
            }
            else if(ele==nums[i]) cnt++;
            else cnt--;
        }


        return ele;
    }
};