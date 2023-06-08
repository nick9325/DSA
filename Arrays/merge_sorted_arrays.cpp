class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(nums1.size()==1) 
        {
            if(nums1[0]==0){
                nums1[0]=1;
            }
            return;
        }

        
        int i=m-1,j=n-1,k=m+n-1;

        while(i>=0 and j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[k--]=nums1[i];
                i--;
            }
            else{
                nums1[k--]=nums2[j--];
            }
            
        }

        for(;j>=0;j--){
            nums1[k--]=nums2[j];
        }

        
    }
};