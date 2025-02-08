class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>result;
        for(int i=0;i<boxes.size();i++){
            result.push_back(boxes[i]-'0');
        }

        vector<int>index1;
         for( int i=0;i<result.size();i++){
            if(result[i]==1){
                index1.push_back(i);
            }
         }

         vector<int>ans;
         for( int i=0;i<result.size();i++){
            int val=0;
            for( int j=0;j<index1.size();j++){
                val+=abs(i-index1[j]);
                
            }
            ans.push_back(val);
         }
         return ans;
        
    }
};