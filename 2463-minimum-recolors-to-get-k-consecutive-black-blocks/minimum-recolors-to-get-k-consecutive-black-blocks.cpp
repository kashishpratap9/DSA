class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=0;
         int r=0;
         int conversion_count=0;
         int mini=INT_MAX;
         while(r<blocks.size()){
            if( blocks[r]=='W'){
                conversion_count++;
            }
            // cout<<conversion_count<<" ";

            if(r-l+1>k){
                if( blocks[l]=='W' && conversion_count>0){
                    conversion_count--;
                }
                l++;
            }
            if(r-l+1==k){
                mini= min(mini, conversion_count);
            }
            r++;

         }

         return mini;
      
        
    }
};