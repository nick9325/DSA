void solve(TreeNode* root, int targetSum,vector<vector<int>> &res,vector<int> v,int sum){
        if(!root) return;
        
        v.push_back(root->val);
        sum+=root->val; 
        
        if(root->left==NULL and root->right==NULL){
            if(sum==targetSum){
                res.push_back(v);
            }
        }
       
        solve(root->left,targetSum,res,v,sum);
        solve(root->right,targetSum,res,v,sum);
        sum-=root->val;
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        vector<int> v;
        solve(root,targetSum,res,v,0);
        
        return res;
        
    }