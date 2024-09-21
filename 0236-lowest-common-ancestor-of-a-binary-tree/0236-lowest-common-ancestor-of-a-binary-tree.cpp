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
    bool find(TreeNode* root,int x,vector<TreeNode*>&a){
        if(root==nullptr)return false;
        a.push_back(root);
        if(root->val==x) return true;
        if(find(root->left,x,a) || find(root->right,x,a)) return true;
        a.pop_back();
        return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<TreeNode*>a1,a2;
       find(root,p->val,a1);
       find(root,q->val,a2);
       int m=a1.size(),n=a2.size();
       TreeNode *ans;
       for(int i=0;i<min(m,n);i++){
        if(a1[i]==a2[i]){
            ans=a1[i];
        }
       }
       return ans;
    }
};