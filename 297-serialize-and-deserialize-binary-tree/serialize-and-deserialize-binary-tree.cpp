/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if( root==NULL){
            return  "x,";
        }

        ans +=to_string( root->val)+ ",";
      
        ans += serialize(root->left);
        ans += serialize(root->right);

        return ans;
        
    }

    TreeNode* Tree(queue<string>&q){
        string s= q.front();
         q.pop();
         if( s=="x"){
             return NULL;
         }
         TreeNode* root= new TreeNode(stoi(s));
         root->left= Tree(q);
         root->right= Tree(q);
         return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      data=data.substr(0, data.size()-1);
    queue<string>q;
    string s;
     for( int i=0;i<data.size();i++){
        char ch = data[i];
         if(ch==','){
            // cout<<s;
             q.push(s);
              s="";
               continue;
         }
           s+=ch; 
     }

     if(s.size()!=0){
         q.push(s);
     }

      return Tree(q);
 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));