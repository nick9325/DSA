class Solution {
public:
    void solve(TreeNode* root1,vector<int> &res){
         if(root1==NULL) return;
         
        solve(root1->left,res);
        solve(root1->right,res);
          if(root1->left==NULL and root1->right==NULL){ 
              res.push_back(root1->val);
          }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> res,res2;
        solve(root1,res);
        solve(root2,res2);
        
        return res==res2;
    }
};