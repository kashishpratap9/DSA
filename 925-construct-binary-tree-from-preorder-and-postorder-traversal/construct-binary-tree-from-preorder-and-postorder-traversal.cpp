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


TreeNode* Construct(vector<int>& preorder,vector<int>&postorder,int s, int e,int&index){
   
     if(s>e || index>=preorder.size()){
        return NULL;
    }
    TreeNode* root= new TreeNode(preorder[index]);
    index++;

    if (s == e) {  // Leaf node case
        return root;
    }
    int i=s;
    while( i<=e && postorder[i] != preorder[index]){
        i++;
    }

    root->left= Construct(preorder, postorder, s, i, index);
    root->right=Construct(preorder, postorder, i+1, e-1, index);
    return root;

   
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int index=0;
       return Construct(preorder, postorder, 0, postorder.size()-1,index);
    }
};