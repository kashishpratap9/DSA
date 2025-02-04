class Solution {
public:

int result= INT_MAX;
void Distribute(int i,vector<int>&temp, vector<int>&cookies,int k){
    int n = cookies.size();
    if( i==n){
        int maxi=0;
        for(int p=0;p<k;p++){
            maxi=max( maxi, temp[p]);
        }

        result= min(result, maxi);
        return;
    }

    for(int j=0;j<k;j++){
        temp[j]+=cookies[i];
        Distribute(i+1, temp, cookies, k);
        temp[j]-=cookies[i];
        
    }
    



}
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>temp(k,0);
         Distribute(0,temp,cookies,k);
         return result;


       
        
    }
};