class Solution {
public:

bool isPlaindrome(string&s){
    int l=0;
     int r=s.size()-1;
     while( l<r){
        if( s[l]!= s[r]){
            return false;
        }
        l++;
        r--;
     }
     return true;
}
    string longestPalindrome(string s) {
        int maxi= 0;
        string result="";
        for(int i=0;i<s.size();i++){
            string ans="";
             for( int j=i;j<s.size();j++){
                ans.push_back(s[j]);
                if(isPlaindrome(ans)){
                    if( maxi<j-i+1){
                        maxi=j-i+1;
                        result= ans;
                    }
                }

             }
        }
        cout<<maxi;
        return result;
        
    }
};