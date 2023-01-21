class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int diff=0;
        if(nums1==nums2 and k==0) return 0;
        if(nums1!=nums2 and k==0) return -1;
        long long stepsi=0,stepsj=0;
        for(int i=0;i<nums1.size();i++){
            
            if(nums1[i]<nums2[i]){
                diff=nums2[i]-nums1[i];
                
                if(diff%k!=0) return -1;
                stepsj+=diff/k;
            }
            else if(nums1[i]>nums2[i]){
                diff=nums1[i]-nums2[i];
                if(diff%k!=0) return -1;
                stepsi+=diff/k;
            }
            
        }
        
        if(stepsi==stepsj) return stepsi;
        return -1;
    }
};