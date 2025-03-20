class Solution {
public:

// TreeNode* createTree(int val , vector<int>&left, vector<int>&right){
//     if( val==-1){
//          return NULL;
//     }
//  TreeNode* node = new TreeNode(val);

//     node->left=createTree(left[val],left, right);
//     node->right=createTree(right[val],left, right);
//     return node;
// }

void dfs(int src, vector<bool>&visited1,  unordered_map<int, vector<int>>&adj){
    visited1[src]=true;
    for(auto nbr: adj[src]){
        if(!visited1[nbr]){
            dfs(nbr, visited1, adj);
        }
    }
}

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        //to check weather a tree is binary tree or not we have to check tree condition
        // 1. it should have only one parent (single parent)
        // 2. exactly one node that have no parents(rootnode)
        // 3. no diconnect compoenet 
     vector<int>cp(n, -1);
     vector<int>visited(n, false);
     for(int i=0;i<n;i++){
        //i is parent;
        //i is the parent of lc and rc;
        int lc=leftChild[i];
        int rc=rightChild[i];
        if(lc!=-1){
            if(!visited[lc]){
            cp[lc]=i;
            visited[lc]= true;
            }else{
                return false;
            }
        }
        if(rc!=-1 ){
            if(!visited[rc]){
            cp[rc]=i;
            visited[rc]=true;
            }else{
                return false;
            }
        }
     }
     int cn=0;
     int root=0;
      for( int i=0;i<cp.size();i++){
         if( cp[i]==-1){
            cn++;
            root=i;
         }
      } 
      if( cn!=1){
        return false;
      }

      unordered_map<int, vector<int>>adj;
      for(int i=0;i<n;i++){
         if (leftChild[i] != -1) adj[i].push_back(leftChild[i]);
        if (rightChild[i] != -1) adj[i].push_back(rightChild[i]);
      }
int count=0;
      vector<bool>visited1(n, false);
     dfs(root, visited1, adj);
     for( int i=0;i<visited1.size();i++){
        if(visited1[i]==false){
            return false;
        }
     }

      return true;

          
    }
};