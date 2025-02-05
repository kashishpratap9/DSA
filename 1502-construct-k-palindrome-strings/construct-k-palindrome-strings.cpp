class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()==k){
             return true;
        }
        if(s.size() < k){ return false;}
        unordered_map<char , int>mp;
        for( int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        int odd_freq=0;
        for( auto i: mp){
             if(i.second%2!=0){
                odd_freq++;
             }
        }

        if( odd_freq<=k){
            return true;
        }

        return false;
        
    }
};