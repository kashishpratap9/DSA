class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>arr1(arr.size());
        int j=1;
        for( int i=0;i<arr.size();i++){
            arr1[i]=arr[i]-j;
            j++; 
        }
        int count=0;
        for( int i=0;i< arr1.size();i++){
           if( arr1[i]==0){
            count++;

           }
        }

        if( count==arr1.size()){
             return arr1.size()+k;
        }

        int l=0;
         int h=arr.size()-1;
        while( l<=h){
             int mid = l + ( h-l)/2;
             if( arr1[mid]<k){
                l= mid+1;
             }else{
                h= mid-1;
             }
        }

        if (h < 0) {
            return k;
        }

        return k-arr1[h] + arr[h];



      
        
    }
};