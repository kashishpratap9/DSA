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

vector<int> helper(TreeNode*&root){
     if(!root){
        return {0,0};
     }
     vector<int>left=helper(root->left);
     vector<int>right=helper(root->right);

     int take= root->val + left[1]+ right[1];
     int notake= max(max(left[0]+right[0], left[0]+ right[1]),max(left[1]+right[0], left[1]+right[1]));

     return {take, notake};


}


    int rob(TreeNode* root) {
      vector<int>ans=helper(root);
      return max( ans[0], ans[1]);
        
    }
};