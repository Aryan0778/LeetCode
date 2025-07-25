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
    TreeNode* helper(TreeNode* root){
        if(root->left==nullptr) return root->right;
        else if(root->right==nullptr) return root->left;
        TreeNode* rightchild=root->right;
        TreeNode* lastright=findright(root->left);
        lastright->right=rightchild;
        return root->left;
    }
    TreeNode* findright(TreeNode* node){
        while(node->right) node=node->right;
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return nullptr;
    if(root->val==key){
        return helper(root);
    }
    TreeNode* node=root;
    while(root){
        if(root->val>key){
            if(root->left && root->left->val==key){
                root->left=helper(root->left);
                break;
            }
            else{
                root=root->left;
            }
        }
        else{
            if(root->right && root->right->val==key){
                root->right=helper(root->right);
                break;
            }
            else{
                root=root->right;
            }
        }
    }
    return node;  
    }
};