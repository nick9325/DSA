class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,INT_MAX);
    }
    
    TreeNode* solve(vector<int> a,int &i,int bound){
        if(i==a.size() || a[i]>bound) return NULL;
        
        TreeNode* root=new TreeNode(a[i++]);
        
        root->left=solve(a,i,root->val);
        root->right=solve(a,i,bound);
        
        return root;
    }
};