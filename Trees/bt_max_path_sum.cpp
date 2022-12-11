class Solution {
private:
    int solve(TreeNode* root,int &mx){
        if(!root) return 0;

        int left=max(0,solve(root->left,mx));
        int right=max(0,solve(root->right,mx));

        mx=max(mx,root->val+left+right);

        return root->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;

        solve(root,mx);

        return mx;
    }
};