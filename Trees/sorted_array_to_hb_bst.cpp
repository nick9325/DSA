class Solution {
public:
    
    TreeNode* sortedArrayToBST(vector<int>& nums,int s,int e){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode* n=new TreeNode(nums[mid]);
        
        n->left=sortedArrayToBST(nums,s,mid-1);
        n->right=sortedArrayToBST(nums,mid+1,e);
        
        return n;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
};