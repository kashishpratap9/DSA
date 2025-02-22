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

TreeNode* prune(TreeNode* &root, bool&flag){
    if(!root){ return NULL;}

    if(!root->left && !root->right&& root->val==0){
         flag= true;
         root= NULL;
        delete(root);
        return NULL;
    }

    root->left= prune(root->left, flag);
    root->right=prune( root->right, flag);
    return root;

}
    TreeNode* pruneTree(TreeNode* root) {
        bool flag= true;
        while( flag){           
        flag = false;  // Reset flag before pruning
        root = prune(root, flag);         
    }         
    return root; 


        
    }
};