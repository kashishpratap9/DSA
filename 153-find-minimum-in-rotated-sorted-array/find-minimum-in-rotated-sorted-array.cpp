class Solution {
public:
    int findMin(vector<int>& arr) {
        int l=0;
         int r= arr.size()-1;
         if(arr.size()==1){
             return arr[0];
         }
         int mini=INT_MAX;

          while(l<=r){
            int mid = l+ ( r-l)/2;
            if(arr[l]<=arr[mid]){
                mini= min(mini, arr[l]);
                l= mid+1;
            }else if(arr[mid]<=arr[r]){
                mini= min( mini, arr[mid]);
                r= mid-1;
            }

          }
          return  mini;
        
    }
};