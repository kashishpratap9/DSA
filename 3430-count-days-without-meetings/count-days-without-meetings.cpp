class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        // vector<bool>visited(days+1, false);
        // int prev=-1;
        int start=0;
         int end=0;
         int dayoff=0;
        for( auto m: meetings){
            start=m[0];
            if( start>end){
            dayoff+=start-end-1;
            }
            //     dayoff+=end-start-1;
            // }
            // cout<<dayoff<<' ';
            end=max(end, m[1]);

        }
        // cout<<dayoff;

        if(end<days){
            dayoff+=days-end;
        }
        // for( int i=1;i<=days;i++){
        //     if(!visited[i]){
        //         dc++;
        //     }
        // }

        return dayoff;

        
    }
};