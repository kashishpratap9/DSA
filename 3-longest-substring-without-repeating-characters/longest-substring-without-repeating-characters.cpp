class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n = s.size();
        int maxlen=0;
        unordered_map<char , int>mp;
         while(r<n){
            if(mp.find(s[r])!= mp.end()){
                while(mp.find(s[r])!= mp.end()){
                    mp[s[l]]--;
                    if( mp[s[l]]==0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
            }

                mp[s[r]]++;
                maxlen=max( maxlen, r-l+1);
                r++;
         }

         return maxlen;

        
        
    }
};