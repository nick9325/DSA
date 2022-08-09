
void solve(TreeNode<int>* root,vector<int> &res){
    if(!root){
        return;
    }
    
    solve(root->left,res);
    res.push_back(root->data);
    solve(root->right,res);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{    
    vector<int> res;
    solve(root,res);
    TreeNode<int> *newroot = new TreeNode<int>(res[0]);
    TreeNode<int>* pre=newroot;
    for(int i=1;i<res.size();i++){
        TreeNode<int> *temp = new TreeNode<int>(res[i]);
        pre->left=NULL;
        pre->right=temp;
        pre=temp;
    }
    pre->left=NULL;
    pre->right=NULL;
    
    return newroot;
    
}
