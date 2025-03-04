class Solution {
public:

bool Compare1(int hash[],string p){
    // unordered_map<char, int>mp1(mp);

    int freq[26]={0};
     for( int i=0;i<p.size();i++){
         freq[p[i]-'a']++;
     }
 for( int i=0;i<26;i++){
     if(hash[i]!=freq[i]){
        return false;
     }
 }
   return true;

}
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int  l=0;
        int  r=0;
        int n=p.size();
        int hash[26]={0};
        // int frequency[26]={0};
        unordered_map<char, int>mp;
        while( r<s.size()){
           hash[s[r]-'a']++;
        //    frequency[s[r]-'a']++;
           if( r-l+1>n){
                hash[s[l]-'a']=hash[s[l]-'a']-1;
                // frequency[s[r]-'a']++;
                l++;
           }

           if(r-l+1==n){
                if(Compare1(hash, p)){
                    ans.push_back(l);
                }
           }
           r++;
        }

        return ans;
        
        
    }
};