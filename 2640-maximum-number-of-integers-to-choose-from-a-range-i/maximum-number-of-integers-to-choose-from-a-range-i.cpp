class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        unordered_set<int>st(banned.begin(), banned.end());
        vector<int>result;
        for(int i=1;i<=n;i++){
             if( st.find(i)== st.end()){
                result.push_back(i);
             }
            
        }
        int sum=0;
        int count=0;
        for(int i=0;i<result.size();i++){
           sum+=result[i];
            if( sum<=maxSum){
                count++;
            }

        }
        return count;



    }
};