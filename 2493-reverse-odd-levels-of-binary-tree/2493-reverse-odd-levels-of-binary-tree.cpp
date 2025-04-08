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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int idx=0;
        while(!q.empty()){
            int sz=q.size();
            vector<TreeNode*>temp;
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(idx%2){
                    temp.push_back(curr);
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            int l=0,r=temp.size()-1;
            while(l<r){
                swap(temp[l++]->val,temp[r--]->val);
            }
            idx++;
        }
        return root;
    }
};