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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,multiset<int>>>mpp;
    vector<vector<int>>ans;
    dfs(root,mpp,0,0);
    for(auto it:mpp){
        vector<int>temp;
        for(auto i:it.second){
            temp.insert(temp.end(),i.second.begin(),i.second.end());
        }
        ans.push_back(temp);
    }
    return ans;   
    }
    void dfs(TreeNode* root,map<int,map<int,multiset<int>>>&mpp,int row,int col){
        if(root==nullptr) return;
        mpp[col][row].insert(root->val);
        dfs(root->left,mpp,row+1,col-1);
        dfs(root->right,mpp,row+1,col+1);
    }
};