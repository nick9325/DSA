/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         map<int,int> m;
        
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        
        TreeNode* root=consTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }
TreeNode* consTree(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie,map<int,int> &m){
    if(ps>pe ||is>ie) return NULL;
    
    
    TreeNode* root=new TreeNode(preorder[ps]);
    int inRoot=m[root->val];
    int leftpart=inRoot-is;
    
    root->left=consTree(preorder,ps+1,ps+leftpart,inorder,is,inRoot-1,m);
    root->right=consTree(preorder,ps+leftpart+1,pe,inorder,inRoot+1,ie,m);
    
    return root;
    
}
};