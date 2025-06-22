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
int Diameter( TreeNode* root, int&maxi){
    if( !root){
         return 0;
    }

    int l = Diameter( root->left, maxi);
    int r= Diameter( root->right , maxi);
     maxi = max( maxi, l+r);

     return 1 + max( l, r);

}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        int ans = Diameter( root, maxi);
        return maxi;
        
    }
};