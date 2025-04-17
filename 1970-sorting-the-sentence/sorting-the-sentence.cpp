class Solution {
public:
    string sortSentence(string s) {
        map<int, string>mp;
        string str="";
        for( int i=0;i<s.size();i++){
             if( s[i]==' '){
                str="";
                continue;
             }else if(isdigit(s[i])){
                mp[s[i]]=str;
             }else{
                str+=s[i];
             }
        }

        string ans="";
        for(auto i:mp){
            ans+=i.second+" ";
        }
        return ans.substr( 0, ans.size()-1);
    
        
    }
};