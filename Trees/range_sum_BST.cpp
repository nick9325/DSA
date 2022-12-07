class Solution {
public:

    // void inorder(TreeNode* root,int low,int high,int &sum){

    //     if(!root) return;

    //     inorder(root->left,low,high,sum);
    //     if(root->val>=low and root->val<=high) sum+=root->val;
    //     inorder(root->right,low,high,sum);
    // }

    int rangeSumBST(TreeNode* root, int low, int high) {
        
        // int sum=0;
        // inorder(root,low,high,sum);

        // return sum;


        if(!root || low>high) return 0;

        if(root->val<low) return rangeSumBST(root->right,low,high);

        if(root->val>high) return rangeSumBST(root->left,low,high);

        return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};