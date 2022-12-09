class Solution {
private:
    void calDiff(TreeNode* root,int &ans,int mx,int mn){
        if(!root) return;

        if(mn!=INT_MAX)
            ans=max(ans,abs(root->val-mn));

        if(mx!=INT_MIN)
            ans=max(ans,abs(root->val-mx));

        mn=min(mn,root->val);
        mx=max(mx,root->val);

        calDiff(root->left,ans,mx,mn);
        calDiff(root->right,ans,mx,mn);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        int mx=INT_MIN;
        int mn=INT_MAX;
        calDiff(root,ans,mx,mn);

        return ans;

    }
};