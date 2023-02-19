class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=0;
        while(!q.empty()){
            int size=q.size();
            vector<int> lev(size);
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                int index=(flag)?size-i-1:i;
                lev[index]=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
           flag=!flag;
           ans.push_back(lev);
        }
        return ans;
    }
};