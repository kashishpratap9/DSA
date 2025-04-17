class Solution {
public:
    string defangIPaddr(string address) {
        string ans ="";
         for( int i=0;i<address.size();i++){
            if(address[i]=='.'){
                // cout<<address[i];
                ans.push_back('[');
                ans.push_back(address[i]);
                ans.push_back(']');
            }
            else if(isdigit(address[i])){
                ans+=address[i];
            }
         }
         return ans;
        
    }
};