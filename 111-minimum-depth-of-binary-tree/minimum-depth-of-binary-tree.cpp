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
int Height(TreeNode* root){
    if(!root){
             return INT_MAX;
         }

         int l =INT_MAX;
         int r= INT_MAX;
         l= minDepth( root->left);
         r= minDepth( root->right);


         if( l != INT_MAX || r!= INT_MAX){
            return 1 + min( l, r);
         }

         return 1;
}
    int minDepth(TreeNode* root) {

        if (!root) return 0;  

    if (!root->left && !root->right) return 1;

    int l = minDepth(root->left);
    int r = minDepth(root->right);

    return 1 + min(l == 0 ? INT_MAX : l, r == 0 ? INT_MAX : r);
  
    }
};