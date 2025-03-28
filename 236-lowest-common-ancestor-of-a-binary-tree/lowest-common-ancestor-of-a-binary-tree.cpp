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
TreeNode* lca(TreeNode*&root, TreeNode*&p, TreeNode*&q){
  if( root==NULL || root==p || root==q){
    return root;
  }

  TreeNode* left = lca( root->left, p, q);
    TreeNode* right= lca( root->right, p, q);
    
    if( left!= NULL && right!=NULL){
        return root;
    }
    if(!left){
        return right;
    }if(!right){
        return left;
    }
    return root;


}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int ans;
        return lca(root, p, q);
        

        
    }
};