class Solution {
private:
    int long long mod=1e9+7;
    long long mx=0;
    long long tot=0;
    int solve(TreeNode* root){
        if(!root) return 0;

        long long sum=root->val+solve(root->left)+solve(root->right);
        mx=max(mx,(tot-sum)*sum);
        return sum;
    }

public:
    int maxProduct(TreeNode* root) {
        tot=solve(root);
        solve(root);

        return mx%mod;
    }
};