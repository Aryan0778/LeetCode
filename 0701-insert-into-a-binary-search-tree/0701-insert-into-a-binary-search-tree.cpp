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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    insert(root,val);
    return root;  
    }
    void insert(TreeNode* root,int val){
        if(root==nullptr) return ;
        if(root->val>val && root->left==nullptr){
            TreeNode* node= new TreeNode(val);
            root->left=node;
            return;
        }
        if(root->val<val && root->right==nullptr){
            TreeNode* node= new TreeNode(val);
            root->right=node;
            return;
        }

        if(root->val>val){
            insert(root->left,val);
        }
        else{
            insert(root->right,val);
        }
    }
};