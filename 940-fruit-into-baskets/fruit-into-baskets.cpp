class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int n = fruits.size();
        int maxlen=0;
        if( fruits.size()==1){
             return 1;
        }
        unordered_map<int,int>mp;
         while(r<n){
            mp[fruits[r]]++;
         
            while(mp.size()>2){
                mp[fruits[l]]--;
                 if( mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                 }
                 l++; 
            }

            if(mp.size()==2){
                maxlen=max(maxlen, r-l+1);
            }
            r++;
         }
         return maxlen==0? fruits.size():maxlen;
        
    }
};