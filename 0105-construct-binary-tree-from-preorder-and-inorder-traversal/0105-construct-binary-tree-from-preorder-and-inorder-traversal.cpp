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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int,int>hash;
    for(int i=0;i<inorder.size();i++) hash[inorder[i]]=i;
    TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,hash);
    return root;
    }
    TreeNode* build(vector<int>& preorder,int pres,int pree,vector<int>& inorder,int ins,int inee,       map<int,int>&mpp){
        if(pres>pree || ins>inee) return nullptr;
        TreeNode* root=new TreeNode(preorder[pres]);
        int inroot=mpp[root->val];
        int numsleft=inroot-ins;
        root->left=build(preorder,pres+1,pres+numsleft,inorder,ins,inroot-1,mpp);
        root->right=build(preorder,pres+numsleft+1,pree,inorder,inroot+1,inee,mpp);
        return root;
    }   
};