class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int>mp;
        mp['a']=-1;
        mp['b']=-1;
        mp['c']=-1;
        int count=0;
    
        for( int i=0;i<s.size();i++){
            mp[s[i]]=i;
            if(mp['a']!=-1 && mp['b']!=-1 && mp['c']!=-1){
                int ans=min(mp['a'], min( mp['b'],mp['c']));
                count+=ans+1;
            }
        }
        return count;
        
    }
};