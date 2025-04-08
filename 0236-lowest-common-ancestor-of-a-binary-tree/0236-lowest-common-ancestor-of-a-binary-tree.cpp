/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ans1,ans2;
        lcs(root,p->val,ans1);
        lcs(root,q->val,ans2);
        TreeNode* ans;
        for(int i=0;i<min(ans1.size(),ans2.size());i++){
            if(ans1[i]==ans2[i]){
                ans=ans1[i];
            }
        }
        
        return ans;
    }
    bool lcs(TreeNode* root,int val,vector<TreeNode*>&ans){
        if(root==NULL) return false;
        ans.push_back(root);
        if(val==root->val) return true;
        bool l=lcs(root->left,val,ans);
        bool r=lcs(root->right,val,ans);
        if(l || r) return true;
        ans.pop_back();
        return false;
    }
};