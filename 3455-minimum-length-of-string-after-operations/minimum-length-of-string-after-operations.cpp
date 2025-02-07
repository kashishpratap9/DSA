class Solution {
public:

    int minimumLength(string s) {

        if(s.length()<=2){
             return s.length();
        }
       
       map<char, int>mp;
       for(int i=0;i<s.size();i++){
        if(mp.find(s[i])==mp.end()|| mp[s[i]]<=2){
                mp[s[i]]++;
        }
         if( mp[s[i]]==3){
            mp[s[i]]= mp[s[i]]-2;
        }
       }
       int count=0;
        for(auto&i : mp){
            cout<<i.first<<" "<<i.second;
            count+=i.second;
        }

        return count;
        
    }
};