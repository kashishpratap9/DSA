class Solution {
public:
bool isPossible( string&str, unordered_set<char>&st){
    for( int i=0;i<str.size();i++){
        st.insert(str[i]);
    }

    return st.size()==1;
}
    int maximumLength(string s) {
        unordered_map<string,int>mp;
        for( int i=0;i<s.size();i++){
            unordered_set<char>st;
             for(int j=i;j<s.size();j++){
                string str= s.substr(i, j-i+1);
               if(isPossible(str, st)){
                    mp[str]++;
               }
             }
            
        }
    int maxlen=-1;
        for(auto i: mp){
            
             if(i.second>=3){
                string val =i.first;
                int len=val.size();
                maxlen= max(maxlen, len);
             }
        }

        return maxlen;
        
    }
};