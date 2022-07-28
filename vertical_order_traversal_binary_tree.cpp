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
    void dfs(TreeNode* root,map<int,map<int,multiset<int>>> &res,int x,int y){
        if(root!=NULL){
            
            res[x][y].insert(root->val);
            
            dfs(root->left,res,x-1,y+1);
            dfs(root->right,res,x+1,y+1);
            
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> res;
        dfs(root,res,0,0);
        vector<vector<int>> ans;
        
        for(auto x:res){
            vector<int> v;
            for(auto y:x.second){
                v.insert(v.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(v);
        }
        
        return ans;
        
        
    }
};