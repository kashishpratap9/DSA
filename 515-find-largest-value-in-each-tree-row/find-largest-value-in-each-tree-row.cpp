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

int height(TreeNode*&root){
    if(!root){
        return 0;
    }
    int left=height(root->left);
    int right= height(root->right);
    return 1+ max( left, right);
}
void dfslargest(TreeNode*&root, int level,vector<int>&ans){
    if(!root){
        return;
    }
    if(ans[level]==-1){
        ans[level]=root->val;
        // cout<<root->val;
    }else{
        ans[level]=max(ans[level], root->val);
    }
    level+=1;
    dfslargest(root->left, level,ans);
    dfslargest(root->right, level,ans);
}
    vector<int> largestValues(TreeNode* root) {
        int level=0;
        int high=height(root);
        vector<int>ans(high,-1);
        // map<int , int>mp;
        dfslargest(root, level, ans);
        // for( auto i:mp){
        //     ans.push_back(i.second);
        // }
        return ans;
        
    }
};