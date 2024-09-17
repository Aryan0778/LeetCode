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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root==nullptr) return{};
    queue<TreeNode*>q;
    vector<vector<int>>ans;
    q.push(root);
    int j=0;
    while(!q.empty()){
        vector<int>ds;
        int n=q.size();
        for(int i=0;i<n;i++){
        TreeNode* node=q.front();
        if(node->left!=NULL){
            q.push(node->left);
        }
        if(node->right!=NULL){
            q.push(node->right);
        }
        ds.push_back(node->val);
        q.pop();
        }
        if(j%2) reverse(ds.begin(),ds.end());
        ans.push_back(ds);
        j++;
    }
    return ans;    
    }
};