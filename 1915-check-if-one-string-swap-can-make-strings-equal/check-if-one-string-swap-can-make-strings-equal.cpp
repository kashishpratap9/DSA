class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
      map<char, int>mp;

      for( int i=0;i<s1.size();i++){
         mp[s1[i]]++;
      }
      for( int i=0;i<s2.size();i++){
       if(mp.find(s2[i]) == mp.end()){
        return false;
       }
       else{



            mp[s2[i]]--;
            if( mp[s2[i]]==0){
                mp.erase(s2[i]);
            }
        
       }

      }

      if(mp.size()==0){
        int i=0; int j=0;
        int count=0;
        while(i<s1.size()&& j<s2.size()){
            if(s1[i]!= s2[j]){
                count++;
            }
            i++;
            j++;
        }
        if(count<=2){
            return true;
        }

      }

      return false;


        
    }
};