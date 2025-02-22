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
TreeNode* delete1(int i,TreeNode* root,  unordered_set<int> to_delete_set, stack<TreeNode*>&ans){
    //base case
    if(!root){
        return NULL;
    }

    
    root->left= delete1(i, root->left, to_delete_set, ans);
    root->right= delete1(i,root->right, to_delete_set, ans);

    if(to_delete_set.count(root->val)){
        if(root->right){
            ans.push(root->right);
        }
          if(root->left){
            ans.push(root->left);
        }
        delete(root);
        return NULL;
        
    }


    return root;


 }


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        stack<TreeNode*>ans;
       unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        TreeNode*node = delete1(0, root, to_delete_set, ans);
        if( node){
            ans.push(node);
        }
        vector<TreeNode*>result;
        while(!ans.empty()){
        result.push_back( ans.top());
        ans.pop();
        }
         return result;

        
    }
};