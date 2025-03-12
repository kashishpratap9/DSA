class Solution {
public:
bool isPossible(string&s, int k){
    int count_0=0;
    int count_1=0;
    for(auto ch:s){
        if(ch=='0'){
            count_0++;
        }else if(ch=='1'){
            count_1++;
        }
    }
    // cout<<count_0<<" "<<count_1;

    return count_0<=k || count_1<=k;
}
    int countKConstraintSubstrings(string s, int k) {
        int count=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                string sub= s.substr(i, j-i+1);
                if(isPossible(sub, k)){
                        count++;
                }
            }
        }

        return count;
        
    }
};