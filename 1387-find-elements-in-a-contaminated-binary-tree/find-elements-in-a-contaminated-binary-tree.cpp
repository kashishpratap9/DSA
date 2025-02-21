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
class FindElements {
public:
unordered_set<int>st;

void Contaminated(TreeNode*& treenode){
    // TreeNode* treenode= root; 
    if(!treenode){
        return;
    }
    if(treenode->left){
        treenode->left->val =  2 *treenode->val+ 1;
        st.insert( treenode->left->val);
        Contaminated(treenode->left);
    }

     if(treenode->right){
        treenode->right->val =  2* treenode->val+ 2;
        st.insert( treenode->right->val);
        Contaminated(treenode->right);
    }
        
}
    FindElements(TreeNode* root) {
       if( root){
        root->val=0;
        st.insert(root->val);
        Contaminated(root);

       }
    }
    
    bool find(int target) {
      if( st.find( target)==st.end()){
        return false;
      }
      return true;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */