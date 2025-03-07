class Solution {
public:

bool minTime(vector<int>&times, int&total, long long t){
    int totalbus=0;
    for(int i=0;i<times.size();i++){
        totalbus=totalbus + (t/times[i]);
         if( totalbus>=total){
        return true;
     }
    }
   
    return false;

}
    long long minimumTime(vector<int>& time, int totalTrips) {
        // long long sum=0;
        long  long  mini=INT_MAX;
        for( int i=0;i<time.size();i++){
            mini= min( mini, (long long)time[i]);
        }
        //  for( int i=0;i<time.size();i++){
        //     sum+=time[i];
        //  }
       long long l=mini;
       long long r=mini*totalTrips;
       long long ans=-1;
        while(l<=r){
            long long mid= l + (r-l)/2;
            if(minTime(time,totalTrips, mid)){
                ans=mid;
                r=mid-1;

            }else{
                l= mid+1;
            }
        }

        return ans;
    
        
    }
};