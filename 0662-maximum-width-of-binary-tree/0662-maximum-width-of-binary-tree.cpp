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
    int widthOfBinaryTree(TreeNode* root) {
    long long maxi=-1;
    queue<pair<TreeNode*,long long>>q;
    q.push({root,0});
    while(!q.empty()){
        int n=q.size();
        long long s=q.front().second;
        long long l=q.back().second;
        maxi=max(maxi,abs(l-s+1));
        for(int i=0;i<n;i++){
            long long ind=q.front().second-s;
            TreeNode* node=q.front().first;
            q.pop();
            if(node->left!=NULL){
                q.push({node->left,2*ind+1});
            }
            if(node->right!=NULL){
                q.push({node->right,2*ind+2});
            }
        }
    } 
    return maxi;   
    }
};