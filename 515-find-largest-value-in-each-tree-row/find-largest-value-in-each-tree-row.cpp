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
void dfslargest(TreeNode*&root, int level, map<int,int>&mp){
    if(!root){
        return;
    }
    if(mp.find(level)==mp.end()){
        mp[level]=root->val;
        // cout<<root->val;
    }else{
        mp[level]=max(mp[level], root->val);
    }
    level+=1;
    dfslargest(root->left, level,mp);
    dfslargest(root->right, level,mp);
}
    vector<int> largestValues(TreeNode* root) {
        int level=0;
        vector<int>ans;
        map<int , int>mp;
        dfslargest(root, level, mp);
        for( auto i:mp){
            ans.push_back(i.second);
        }
    
        return ans;
        
    }
};