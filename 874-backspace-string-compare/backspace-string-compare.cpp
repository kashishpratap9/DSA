class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<int>ans;
        string s1="";
        string s2="";
        for( int i=0;i<s.size();i++){
             if( s[i]=='#' && s1.size()!=0){
                s1.pop_back();
             }else if(s[i]!='#'){
                s1.push_back(s[i]);
             }
        }
        cout<<s1<<endl;
        for( int i=0;i<t.size();i++){
            if( t[i]=='#' && s2.size()!=0){
                s2.pop_back();
            }else if( t[i] != '#'){
                s2.push_back(t[i]);
            }
        }
        cout<<s2;

        return s1==s2;
       
    }
};