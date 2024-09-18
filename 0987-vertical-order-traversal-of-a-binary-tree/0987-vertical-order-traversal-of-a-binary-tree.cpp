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
    map<int,multiset<int>>mpp;
    vector<vector<int>>ans;
    traverse(root,mpp,0);
    for(auto it:mpp){
        multiset<int>temp=it.second;
        vector<int>ps;
        for(auto it:temp) ps.push_back(it);
        ans.push_back(ps);
    }
    return ans;
    
    }
    void traverse(TreeNode* root,map<int,multiset<int>>&mpp,int i){
    if(root==nullptr) return;
    mpp[i].insert(root->val);
    traverse(root->left,mpp,i-1);
    traverse(root->right,mpp,i+1);
    } 
};