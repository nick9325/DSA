class Solution {
public:
    
    void solve(TreeNode* r1,TreeNode* r2,int l){
        
        if(!r1 and !r2) return;
        
        if(l%2==0){
            swap(r1->val,r2->val);
        }
        
        solve(r1->left,r2->right,l+1);
        solve(r1->right,r2->left,l+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        
        solve(root->left,root->right,0);
        
       return root;
        
    }
};