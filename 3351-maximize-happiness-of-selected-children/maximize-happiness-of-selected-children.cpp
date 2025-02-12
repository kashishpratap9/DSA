class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {

        priority_queue<int>pq(arr.begin(), arr.end());
       long long  result=0;
        int i=0;
        while(k!=0){
            int val = pq.top()-i;
            pq.pop();
            if(val > 0){
                result+=val;
                // cout<<result;
            }
            k--;
            i++;
        }
        return result;
    }
};