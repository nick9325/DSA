int solve(Node* &root,int &ans){
    
    if(root==NULL) return INT_MAX;
    
    int left=solve(root->left,ans);
    int right=solve(root->right,ans);
    
    ans=max(ans,max(root->data-left,root->data-right));
    
    return min(left,min(root->data,right));
    
}

int maxDiff(Node* root)
{
    int ans=INT_MIN;
    
    solve(root,ans);
    
    return ans;
}