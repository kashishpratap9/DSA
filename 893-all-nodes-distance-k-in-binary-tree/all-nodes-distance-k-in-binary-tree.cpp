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


void Parent( TreeNode*&root, unordered_map<TreeNode*, TreeNode*>&mp){
    if( !root){
        return ;
    }
    if(root->left){
        mp[root->left]=root;
    }
     Parent( root->left, mp);
    
    if( root->right){
       mp[root->right]=root;
    }
     Parent( root->right, mp);

}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>mp;
        Parent( root, mp);
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<TreeNode*>visited;
        visited.insert(target);
        int l=0;
        while(!q.empty()){
            int size= q.size();
            if(l==k){
                 break;
            }
            for( int i=0;i<size;i++){
                 TreeNode* node = q.front();
                q.pop();
        
                if(node->left && visited.find(node->left)==visited.end()){
                    visited.insert(node->left);
                    q.push({node->left});
                } if(node->right && visited.find(node->right)==visited.end()){
                    visited.insert( node->right);
                    q.push({node->right});
                }if(mp.find(node)!=mp.end() && visited.find(mp[node])==visited.end()){
                    visited.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
            l++;
        }
vector<int>ans;
        while(!q.empty()){
            TreeNode* node= q.front();
             ans.push_back(node->val);
             q.pop();
        }
        return ans;
        
    }
};