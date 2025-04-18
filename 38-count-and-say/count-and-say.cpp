class Solution {
public:

string  RLE(string&str, string&ans){
    int count=1;
    bool flag= false;
    for( int i=0;i<str.size();i++){
        int count=1;
        while(i+1 <str.size() && str[i]==str[i+1]){
            count++;
            i++;
        }
      
        ans.push_back(count+'0');
        ans.push_back(str[i]);
           
       
    }

    return ans;
   
}
    string countAndSay(int n) {
        int num=2;
        string str="1";
        while(num<=n){
            string ans="";
            str=RLE(str, ans);
            cout<<str<<" ";
            num++;
        }
        return str;
       
        
    }
};