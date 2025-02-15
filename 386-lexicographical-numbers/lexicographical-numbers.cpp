class Solution {
public:

void inOrder( int i, int n, vector<int>&ans){
    //base case
    if(i>n){
        return;
    }

    ans.push_back(i);
    for( int j=0;j<10;j++){
        int num= i*10+ j;
        if( num>n){
            break;
        }
        // ans.push_back(num);
        inOrder(num, n, ans);
    }
}
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            inOrder(i,n, ans);
        }
        return ans;
        
    }
};